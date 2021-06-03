pybind11_add_module(MyDev PyMyDev.cpp)
target_link_libraries(MyDev PRIVATE mydev::mydev spdlog::spdlog_header_only)