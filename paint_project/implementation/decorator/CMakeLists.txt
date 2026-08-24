add_library(decorators STATIC)
target_sources(decorators PRIVATE 
    src/shape_decorator.cpp
    src/smooth_move_decorator.cpp
)

target_include_directories(decorators PUBLIC include)
target_link_libraries(decorators PUBLIC utils elements)
