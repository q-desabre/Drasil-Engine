MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.hpp)
    SET(dir_list "")

    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()

    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)

project(drasil)

HEADER_DIRECTORIES(header_dir_list)

add_library(drasil SHARED)
set_property(TARGET drasil PROPERTY ENABLE_EXPORTS ON)

# add sfml
find_package(SFML 2.5 COMPONENTS graphics audio network REQUIRED)
target_link_libraries(drasil PUBLIC sfml-graphics sfml-audio sfml-network)

# keep typeid revelant outside lib boundary
# target_compile_definitions(drasil PUBLIC -D_GLIBCXX_USE_CXX11_ABI=0)
target_compile_definitions(drasil PRIVATE DLL_EXPORT)

# set variable for source files of Core/ as *.cpp
file(GLOB_RECURSE CORE_SRC "Core/*.cpp")

# set variable for source files of System/ as *.cpp
file(GLOB_RECURSE SYSTEM_SRC "Systems/*.cpp")

# set variable for source files of Game/ as *.cpp
file(GLOB_RECURSE GAME_SRC "Actors/*.cpp")

# set include directories
# recursive search for header files
list(LENGTH header_dir_list header_dir_list_count)
message(STATUS "[INFO] Found ${header_dir_list_count} header directories.")

target_include_directories(drasil PUBLIC ${header_dir_list})

# set source to target
target_sources(drasil PRIVATE ${CORE_SRC} ${SYSTEM_SRC} ${GAME_SRC})

# copy binary to bin folder
add_custom_command(TARGET drasil POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:drasil>
    ../../Nexus/build)

add_custom_command(TARGET drasil POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:drasil>
    ../../Games/Menu/build)

add_custom_command(TARGET drasil POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:drasil>
    ../../Graphicals/SFML/build)
