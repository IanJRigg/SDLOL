cmake_minimum_required(VERSION 3.12)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SDLOL_INCLUDE_DIR ${INCLUDE_DIR}/sdlol)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)


# SDLOL Library Configuration
###############################################################################
set(LIBRARY_NAME SDLOL)
project(${LIBRARY_NAME} VERSION 1.0 LANGUAGES CXX)

set(SOURCE_FILES
    ${SRC_DIR}/font.cpp
    ${SRC_DIR}/label.cpp
    ${SRC_DIR}/renderer.cpp
    ${SRC_DIR}/sdl-controller.cpp
    ${SRC_DIR}/surface.cpp
    ${SRC_DIR}/texture.cpp
    ${SRC_DIR}/window.cpp
)

set(HEADER_FILES
    ${SDLOL_INCLUDE_DIR}/font.h
    ${SDLOL_INCLUDE_DIR}/input.h
    ${SDLOL_INCLUDE_DIR}/label.h
    ${SDLOL_INCLUDE_DIR}/renderer.h
    ${SDLOL_INCLUDE_DIR}/sdl-controller.h
    ${SDLOL_INCLUDE_DIR}/exception.h
    ${SDLOL_INCLUDE_DIR}/surface.h
    ${SDLOL_INCLUDE_DIR}/texture.h
    ${SDLOL_INCLUDE_DIR}/window.h
)

find_package(SDL2       REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL_ttf    REQUIRED)

add_library(
    ${LIBRARY_NAME}
    SHARED
        ${SOURCE_FILES}
        ${HEADER_FILES}
)

set_target_properties(
    ${LIBRARY_NAME}
    PROPERTIES
        # C++ version information
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO

        # Public Header file location
        PUBLIC_HEADER "${HEADER_FILES}"
)

target_compile_options(
    ${LIBRARY_NAME}
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${INCLUDE_DIR}
    PRIVATE
        ${SDLOL_INCLUDE_DIR}
)

target_link_libraries(
    ${LIBRARY_NAME}
    PUBLIC
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)

install(
    TARGETS
        ${LIBRARY_NAME}
    LIBRARY DESTINATION
        ${LIB_DIR}
    PUBLIC_HEADER DESTINATION
        # include folder already exists
)

# For use later
# include(GNUInstallDirs)
# install(
#     TARGETS
#         ${LIBRARY_NAME}
#     LIBRARY DESTINATION
#         ${CMAKE_INSTALL_LIBDIR}
#     PUBLIC_HEADER DESTINATION
#         ${CMAKE_INSTALL_INCLUDEDIR}
# )


# Test Application Configuration
###############################################################################
set(APPLICATION_NAME SDLOL-test)
project(${APPLICATION_NAME} VERSION 1.0 LANGUAGES CXX)

set(TEST_SOURCE_FILES
    # ${TEST_DIR}/test-font.cpp
    ${TEST_DIR}/test-renderer.cpp
    ${TEST_DIR}/test-runner.cpp
    ${TEST_DIR}/test-surface.cpp
    # ${TEST_DIR}/test-texture.cpp
    ${TEST_DIR}/test-window.cpp
)

set(TEST_HEADER_FILES
    ${TEST_DIR}/catch.hpp
    ${TEST_DIR}/constants.h
)

add_executable(
    ${APPLICATION_NAME}
    ${TEST_SOURCE_FILES}
    ${TEST_HEADER_FILES}
)

set_target_properties(
    ${APPLICATION_NAME}
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_include_directories(
    ${APPLICATION_NAME}
    PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${SDLOL_INCLUDE_DIR}
)

target_link_libraries(
    ${APPLICATION_NAME}
    PRIVATE
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${LIBRARY_NAME}
)