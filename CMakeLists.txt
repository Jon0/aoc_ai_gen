cmake_minimum_required (VERSION 2.6)

project (AocAiGen)

set (Test_VERSION_MAJOR 0)
set (Test_VERSION_MINOR 0)

file(GLOB SRC_FILES
    "src/*.cpp"
    "src/parser/*.cpp"
)

add_definitions(-std=c++11)
add_executable (AocAiGenMain ${SRC_FILES})
target_link_libraries (AocAiGenMain)
