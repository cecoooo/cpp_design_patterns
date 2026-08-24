add_library(elements STATIC)
target_sources(elements PRIVATE 
    src/coal.cpp
    src/iron.cpp
    src/player.cpp
    src/resource.cpp
    src/stone.cpp
    src/wood.cpp
)
target_include_directories(elements PUBLIC include)
target_link_libraries(elements PUBLIC utils environment collect_strategy)