cmake_minimum_required(VERSION 3.16)

project(sfml_hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sfml_hello
    main.cpp
)


list(APPEND CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML")

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

if(SFML_FOUND)
    target_include_directories(sfml_hello PRIVATE ${SFML_INCLUDE_DIR})
    target_link_libraries(sfml_hello PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
    )
endif()