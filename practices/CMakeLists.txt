
# 001
add_executable(p001 001_medium.cc)
target_link_libraries(p001 gtest gtest_main Threads::Threads)
gtest_discover_tests(p001)

# 002
add_executable(p002 002_bounds.cc)
target_link_libraries(p002 gtest gtest_main Threads::Threads)
gtest_discover_tests(p002)
