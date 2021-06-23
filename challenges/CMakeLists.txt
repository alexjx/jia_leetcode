

# 004
add_executable(c004 004_median_of_two_sorted_array.cc)
target_link_libraries(c004 gtest gtest_main Threads::Threads)
gtest_discover_tests(c004)
