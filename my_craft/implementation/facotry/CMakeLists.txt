add_library(factory STATIC)
target_sources(factory PRIVATE 
    src/resource_factory.cpp
    src/plugin_loader.cpp
)

target_include_directories(factory PUBLIC include)
target_link_libraries(factory PUBLIC utils elements)

set(PLUGIN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/plugins)

add_library(coal_plugin MODULE plugins/coal_plugin.cpp)
target_include_directories(coal_plugin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(coal_plugin PRIVATE factory utils elements)
set_target_properties(coal_plugin PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_DIR})

add_library(iron_plugin MODULE plugins/iron_plugin.cpp)
target_include_directories(iron_plugin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(iron_plugin PRIVATE factory utils elements)
set_target_properties(iron_plugin PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_DIR})

add_library(stone_plugin MODULE plugins/stone_plugin.cpp)
target_include_directories(stone_plugin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(stone_plugin PRIVATE factory utils elements)
set_target_properties(stone_plugin PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_DIR})

add_library(wood_plugin MODULE plugins/wood_plugin.cpp)
target_include_directories(wood_plugin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(wood_plugin PRIVATE factory utils elements)
set_target_properties(wood_plugin PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_DIR})