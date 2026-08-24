add_library(collect_strategy STATIC)
target_sources(collect_strategy PRIVATE 
    src/closest_point_strategy.cpp
    src/greedy_strategy.cpp
)

target_include_directories(collect_strategy PUBLIC include)
target_link_libraries(collect_strategy PUBLIC environment utils)