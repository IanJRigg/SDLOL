cmake_minimum_required(VERSION 3.12)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)


# SDLOL Library Configuration
###############################################################################
set(LIBRARY_NAME SDLOL)
project(${LIBRARY_NAME} VERSION 1.0 LANGUAGES CXX)

set(SOURCE_FILES "")
set(HEADER_FILES "")

add_subdirectory(${SRC_DIR})
add_subdirectory(${INCLUDE_DIR})

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
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
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
    PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${INCLUDE_DIR}
)

target_link_libraries(
    ${LIBRARY_NAME}
    PRIVATE
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)

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

set(TEST_SOURCE_FILES "")
set(TEST_HEADER_FILES "")

add_subdirectory(${TEST_DIR})

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
        ${INCLUDE_DIR}
)

target_link_libraries(
    ${APPLICATION_NAME}
    PRIVATE
        ${LIBRARY_NAME}
)