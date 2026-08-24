cmake_minimum_required(VERSION 3.16)

project(my_craft LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_subdirectory(utils)
add_subdirectory(environment)
add_subdirectory(elements)
add_subdirectory(resource_collect_strategy)
add_subdirectory(factory)

add_executable(my_craft main.cpp)

target_link_libraries(my_craft PRIVATE 
    utils 
    environment 
    elements
    collect_strategy
    factory
    SFML::Graphics
    SFML::Window
    SFML::System
)