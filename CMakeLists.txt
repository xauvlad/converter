cmake_minimum_required(VERSION 3.15)
#Замените этот путь
set(CMAKE_TOOLCHAIN_FILE "C:/Users/xauvlad/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Converter)

find_package(OpenCV REQUIRED)

add_executable(convert src/main.cpp)

target_link_libraries(convert PRIVATE ${OpenCV_LIBS})

target_include_directories(convert PRIVATE ${OpenCV_INCLUDE_DIRS})

# install(TARGETS convert DESTINATION bin)

# if(WIN32)
#     install(FILES ${OpenCV_RUNTIME_FILES} DESTINATION bin)
# endif()