cmake_minimum_required(VERSION 3.18)

project(sdl_game)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_DIR "C:/Users/filsh/Documents/sdl_game/SDL/lib/cmake/SDL2")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE "/ENTRY:WinMainCRTStartup")
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

if (WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
        VERBATIM
    )
endif ()




