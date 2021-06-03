cmake_minimum_required(VERSION 3.0.0)
project(MyCppPrj VERSION 0.1.0)

find_package(Threads REQUIRED)


add_subdirectory(3rdparty)
add_subdirectory(cpp)
add_subdirectory(cli)
# add_subdirectory(pybind)
add_subdirectory(tests)

