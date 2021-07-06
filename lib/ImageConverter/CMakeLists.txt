set(LIB_NAME ImageConverter)

project(${LIB_NAME})

set(SOURCES
     ImageConverter.cpp
   )

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_library(${LIB_NAME} ${SOURCES})

target_include_directories(${LIB_NAME}
                            PRIVATE headers/${LIB_NAME}
                            PUBLIC headers/
                          )

target_link_libraries(${LIB_NAME}
                        PUBLIC ${OpenCV_LIBS}
                      )
