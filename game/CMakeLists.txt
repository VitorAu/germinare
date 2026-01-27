add_executable(game main.cpp)

# target_sources(game PRIVATE src/main.cpp)

target_link_libraries(game PRIVATE engine)
