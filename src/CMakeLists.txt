set(CMAKE_CXX_FLAGS "-fstandalone-debug")

add_executable(${PROJECT_NAME}  main.cpp)

SET(CTEST_OUTPUT_ON_FAILURE TRUE)

add_executable(unit_tests
    test/insertion_sort.test.cpp
    test/quick_sort.test.cpp
    test/merge_sort.test.cpp
    test/heap_sort.test.cpp)
target_link_libraries(unit_tests gtest_main)
gtest_discover_tests(unit_tests)