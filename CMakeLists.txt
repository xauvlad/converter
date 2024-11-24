cmake_minimum_required(VERSION 3.15)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/xauvlad/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Converter)

find_package(OpenCV REQUIRED)

add_executable(Converter src/main.cpp)

target_link_libraries(Converter PRIVATE ${OpenCV_LIBS})

target_include_directories(Converter PRIVATE ${OpenCV_INCLUDE_DIRS})
