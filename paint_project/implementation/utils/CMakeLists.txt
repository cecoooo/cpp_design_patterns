add_library(utils STATIC)
target_sources(utils PRIVATE src/vector_2d.cpp)
target_include_directories(utils PUBLIC include)