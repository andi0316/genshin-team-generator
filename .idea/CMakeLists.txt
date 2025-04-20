cmake_minimum_required(VERSION 3.29)
project(_idea)

set(CMAKE_CXX_STANDARD 14)

add_executable(_idea
    editor.xml
    genshin-team-generator.iml
    modules.xml
    vcs.xml
        ../main.cpp)
