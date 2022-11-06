cmake_minimum_required(VERSION 3.14)

# set CMAKE_CXX to c++20
set(CMAKE_CXX_STANDARD 20)

project(ecs)

add_executable(ecs main.cpp)

# set variable for source files of Core/ as *.cpp
file(GLOB_RECURSE CORE_SRC "Core/*.cpp")

# set variable for source files of System/ as *.cpp
file(GLOB_RECURSE SYSTEM_SRC "Systems/*.cpp")

# set variable for source files of Game/ as *.cpp
file(GLOB_RECURSE GAME_SRC "Game/*.cpp")

# set variable to main.cpp
set(MAIN_SRC "main.cpp")

# set include directories
target_include_directories(ecs PUBLIC "Core" "Systems" "Components" "Types")

# set source to target
target_sources(ecs PRIVATE ${CORE_SRC} ${SYSTEM_SRC} ${MAIN_SRC} ${GAME_SRC})

# Core and subdirectories target include
target_include_directories(ecs PUBLIC "Core" "Core/System" "Core/Entity" "Core/Event" "Core/Component")

target_include_directories(ecs PUBLIC "Systems" "Systems/Render" "Systems/Physics" "Systems/PlayerController")

target_include_directories(ecs PUBLIC "Types" "Types/Maths")

target_include_directories(ecs PUBLIC "Components")

target_include_directories(ecs PUBLIC "Game")

# add sfml
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(ecs sfml-graphics sfml-audio)