add_library(commander STATIC)
target_sources(commander PRIVATE 
    src/move_command.cpp
    src/rotate_command.cpp
    src/scale_command.cpp
    src/undo_redo_commander.cpp
)

target_include_directories(commander PUBLIC include)
target_link_libraries(commander PUBLIC utils elements)