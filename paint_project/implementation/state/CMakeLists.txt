add_library(state STATIC)
target_sources(state PRIVATE 
    src/context.cpp
    src/rotate_state.cpp
    src/move_state.cpp
    src/click_state.cpp
)

target_include_directories(state PUBLIC include)
target_link_libraries(state PUBLIC utils elements)