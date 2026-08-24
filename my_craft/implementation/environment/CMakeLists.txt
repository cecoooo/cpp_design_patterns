add_library(environment STATIC)
target_sources(environment PRIVATE 
    src/window.cpp
    src/world.cpp
    src/resource_map.cpp
)
target_include_directories(environment PUBLIC include)
target_link_libraries(environment PUBLIC
    SFML::Graphics
    SFML::Window
    SFML::System
    utils 
    elements)