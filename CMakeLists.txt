cmake_minimum_required(VERSION 3.13)
project(SIMPLE_ASCII_IMAGE_GENERATOR)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(lib/ImageConverter)

add_executable(simple_ascii_image_generator ${SOURCE_FILES})
target_include_directories(simple_ascii_image_generator PRIVATE inc)

target_link_libraries(simple_ascii_image_generator ${OpenCV_LIBS}
                       PRIVATE ImageConverter
                     )
