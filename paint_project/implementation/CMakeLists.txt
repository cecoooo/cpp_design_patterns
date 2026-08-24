cmake_minimum_required(VERSION 3.16)

project(paint_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(paint_project
    main.cpp
)

add_subdirectory(utils)
add_subdirectory(elements)
add_subdirectory(decorators)
add_subdirectory(sfml_adapter)
add_subdirectory(commander)
add_subdirectory(visitor)
add_subdirectory(state)

target_link_libraries(paint_project PRIVATE
    utils
    elements
    decorators
    sfml_adapter
    commander
    visitor
    state
)