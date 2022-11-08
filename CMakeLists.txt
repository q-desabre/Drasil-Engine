cmake_minimum_required(VERSION 3.14)

# set CMAKE_CXX to c++20
set(CMAKE_CXX_STANDARD 20)

project(ecs)

add_executable(server)
add_executable(client)

# set variable for source files of Core/ as *.cpp
file(GLOB_RECURSE CORE_SRC "Core/*.cpp")

# set variable for source files of System/ as *.cpp
file(GLOB_RECURSE SYSTEM_SRC "Systems/*.cpp")

# set variable for source files of Game/ as *.cpp
file(GLOB_RECURSE GAME_SRC "Game/*.cpp")

# set variable to server.cpp
set(SERVER_SRC "server.cpp")

# set variable to client.cpp
set(CLIENT_SRC "client.cpp")

# set source to target
target_sources(server PRIVATE ${CORE_SRC} ${SYSTEM_SRC} ${SERVER_SRC} ${GAME_SRC})

# set source to target
target_sources(client PRIVATE ${CORE_SRC} ${SYSTEM_SRC} ${CLIENT_SRC} ${GAME_SRC})

# Core and subdirectories target include
target_include_directories(server
    PUBLIC "Core"
    "Core/System"
    "Core/Entity"
    "Core/Event"
    "Core/Component"
    "Core/Drasil"
    "Core/Level"
    "Core/Manager"
    "Core/Coordinator")

target_include_directories(server
    PUBLIC "Systems"
    "Systems/Render"
    "Systems/Physics"
    "Systems/PlayerController")

target_include_directories(server
    PUBLIC "Types"
    "Types/Maths")

target_include_directories(server
    PUBLIC "Components")

target_include_directories(server
    PUBLIC "Game")

target_include_directories(server
    PUBLIC "Tools" "Interface")

# Core and subdirectories target include
target_include_directories(client
    PUBLIC "Core"
    "Core/System"
    "Core/Entity"
    "Core/Event"
    "Core/Component"
    "Core/Drasil"
    "Core/Level"
    "Core/Manager"
    "Core/Coordinator")

target_include_directories(client
    PUBLIC "Systems"
    "Systems/Render"
    "Systems/Physics"
    "Systems/PlayerController")

target_include_directories(client
    PUBLIC "Types"
    "Types/Maths")

target_include_directories(client
    PUBLIC "Components")

target_include_directories(client
    PUBLIC "Game")

target_include_directories(client
    PUBLIC "Tools" "Interface")

# add sfml
find_package(SFML 2.5 COMPONENTS graphics audio network REQUIRED)
target_link_libraries(server sfml-graphics sfml-audio sfml-network)
target_link_libraries(client sfml-graphics sfml-audio sfml-network)