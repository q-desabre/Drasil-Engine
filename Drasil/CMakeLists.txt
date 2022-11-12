cmake_minimum_required(VERSION 3.14)

# set CMAKE_CXX to c++20
set(CMAKE_CXX_STANDARD 20)

project(drasil)

# make shared library named drasil
add_library(drasil SHARED)

# set variable for source files of Core/ as *.cpp
file(GLOB_RECURSE CORE_SRC "Core/*.cpp")

# set variable for source files of System/ as *.cpp
file(GLOB_RECURSE SYSTEM_SRC "Systems/*.cpp")

# set variable for source files of Game/ as *.cpp
file(GLOB_RECURSE GAME_SRC "Game/*.cpp")

# set source to target
target_sources(drasil PRIVATE ${CORE_SRC} ${SYSTEM_SRC} ${GAME_SRC})

# # Core and subdirectories target include
# target_include_directories(drasil
# PUBLIC "Core"
# "Core/System"
# "Core/Entity"
# "Core/Event"
# "Core/Component"
# "Core/Drasil"
# "Core/Level"
# "Core/Manager"
# "Core/Coordinator")

# target_include_directories(drasil
# PUBLIC "Systems"
# "Systems/Network"
# "Systems/Render"
# "Systems/Physics"
# "Systems/PlayerController")

# target_include_directories(drasil
# PUBLIC "Types"
# "Types/Maths")

# target_include_directories(drasil
# PUBLIC "Components")

# target_include_directories(drasil
# PUBLIC "Game")

# target_include_directories(drasil
# PUBLIC "Tools" "Interface")

# add sfml
find_package(SFML 2.5 COMPONENTS graphics audio network REQUIRED)
target_link_libraries(drasil sfml-graphics sfml-audio sfml-network)

# copy binary to bin folder
add_custom_command(TARGET drasil POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:drasil>
    ../../SampleGame/build)
