cmake_minimum_required(VERSION 3.13)
project(SIMPLE_ASCII_IMAGE_GENERATOR)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/main.cpp src/ImageConverter.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(simple_ascii_image_generator ${SOURCE_FILES})
target_include_directories(simple_ascii_image_generator PRIVATE inc)

target_link_libraries(simple_ascii_image_generator ${OpenCV_LIBS})
