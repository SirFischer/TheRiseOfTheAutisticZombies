cmake_minimum_required(VERSION 3.16.3)
project(TheRiseOfTheAutisticZombies VERSION 0.5.0)

include(FetchContent)

set(EXECUTABLE_NAME TheArtOfKillingZombies)

set(SFML_VERSION "2.5.1")

FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

add_executable(${EXECUTABLE_NAME} main.cpp)

target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
)

target_compile_options(${EXECUTABLE_NAME} PRIVATE -Wall -Werror -Wextra)