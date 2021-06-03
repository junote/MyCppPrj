add_executable(mycli Main.cpp)
target_compile_definitions(mycli PRIVATE CLI_EXAMPLES_USE_LOOP_SCHEDULER )
target_link_libraries(mycli PUBLIC cli::cli mydev::mydev spdlog::spdlog_header_only)
set_property(TARGET mycli PROPERTY CXX_STANDARD 17)




