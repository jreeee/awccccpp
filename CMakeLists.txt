cmake_minimum_required(VERSION 3.25)
project(aw4cpp LANGUAGES CXX)

set(FRAMEWORK_NAME frw)

add_subdirectory(ext/curlpp)

add_executable(aw4cpp)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/frw/*.cpp)
target_include_directories(aw4cpp SYSTEM PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ext/curlpp/include/)

target_link_libraries(aw4cpp curlpp curl) # set curl required

target_sources(aw4cpp
  PRIVATE
    src/main.cpp
    ${SRC_FILES}
)

set_target_properties(aw4cpp
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

