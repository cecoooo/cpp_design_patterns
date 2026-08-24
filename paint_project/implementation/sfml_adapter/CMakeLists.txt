add_library(sfml_adapter STATIC)

set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

target_sources(sfml_adapter PRIVATE
    src/window.cpp
    src/sfml_window_adapter.cpp
)

target_include_directories(sfml_adapter PUBLIC include)
target_link_libraries(sfml_adapter PUBLIC 
    utils
    SFML::Graphics
    SFML::Window
    SFML::System)