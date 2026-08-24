cmake_minimum_required(VERSION 3.16)

project(prj LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    src/tire.cpp
    src/engine.cpp
    src/car.cpp
    src/player.cpp
    src/garage.cpp
    src/race.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Public headers are in include/
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)