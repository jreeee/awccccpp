cmake_minimum_required(VERSION 3.25)
project(awccccpp LANGUAGES CXX)

#add_subdirectory(frw)
add_subdirectory(ext/curlpp)

add_executable(app)

target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ext/curlpp/include/)

target_link_libraries(app curlpp curl) # set curl required

target_sources(app
  PRIVATE
    src/main.cpp
)

set_target_properties(app
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

