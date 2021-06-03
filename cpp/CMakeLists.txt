file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB headers CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.h )

add_library(mydev ${sources} ${headers})
add_library(mydev::mydev ALIAS mydev)
target_compile_options(mydev PRIVATE -fPIC)
target_include_directories(mydev PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mydev PUBLIC spdlog::spdlog_header_only)

add_executable(mydevmain ${sources} ${headers})
target_link_libraries(mydevmain PRIVATE spdlog::spdlog )