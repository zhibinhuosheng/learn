cmake_minimum_required(VERSION 3.0)
project(CALC)
set(CMAKE_CXX_STANDARD 11)
file(GLOB SRC_LIST src/*.cpp)

# target_include_directories(app1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/op)
add_library(op SHARED ${SRC_LIST})
target_include_directories(op PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/op)

set_target_properties(op PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/lib/shared
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/lib/static
)
# set (LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/lib/static)
# link_directories(${RUNTIME_OUTPUT_DIRECTORY})
# link_libraries(op)
file(GLOB MAIN ./*.cpp)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(app ${MAIN})

target_link_options(app PRIVATE
    "-Wl,-rpath,../lib/shared")
target_link_libraries(app PRIVATE op)