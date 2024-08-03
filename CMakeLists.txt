cmake_minimum_required(VERSION 3.25)
project(awccccpp LANGUAGES CXX)

#add_subdirectory(frw)
add_subdirectory(ext/curlpp) # Change `ext/curlcpp` to a directory according to your setup

add_executable(app)

target_include_directories(app PRIVATE ${CURLPP_SOURCE_DIR}/include)

target_sources(app
  PRIVATE
    src/main.cpp
)
set_target_properties(app
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
