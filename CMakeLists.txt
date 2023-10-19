cmake_minimum_required(VERSION 3.18)

project(sdl_game)

set(CMAKE_CXX_STANDARD 17)

#Find SDL2 Core Library
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/SDL_Library/SDL/lib/cmake/SDL2")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
#end

#Find SDL2_image
set(SDL2_image_DIR "${CMAKE_SOURCE_DIR}/SDL_Library/SDL_Image/lib/cmake/SDL2_image")
find_package(SDL2_image REQUIRED)
include_directories("${CMAKE_SOURCE_DIR}/SDL_Library/SDL_Image/include")
message("Hello! ${SDL2_IMAGE_INCLUDE_DIRS}")

file(GLOB SOURCES "src/*.cpp")
set(LIBRARY_SOURCES ${SOURCES})

file(GLOB HEADERS "include/*.h")
set(LIBRARY_HEADERS ${HEADERS})

add_library(GAME_LIBRARY STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

target_include_directories(GAME_LIBRARY
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)



add_executable(${PROJECT_NAME} main.cpp )

target_link_options(${PROJECT_NAME} PRIVATE "/ENTRY:WinMainCRTStartup")
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} GAME_LIBRARY)

if (WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
        VERBATIM
    )
endif ()




