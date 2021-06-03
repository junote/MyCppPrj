add_executable(mytest tests.cpp)
# gtest_main need to place at first
target_link_libraries(mytest PUBLIC gtest_main mydev::mydev  Threads::Threads spdlog::spdlog_header_only)