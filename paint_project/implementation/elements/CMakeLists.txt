add_library(elements STATIC)
target_sources(elements PRIVATE 
    src/canvas.cpp
    src/circle.cpp
    src/rectangle.cpp
    src/shape.cpp
)

target_include_directories(elements PUBLIC include)
target_link_libraries(elements PUBLIC utils sfml_adapter visitor)