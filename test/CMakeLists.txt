cmake_minimum_required(VERSION 3.12)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(TEST_SOURCE_FILES
    ${TEST_SOURCE_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/test-font.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test-renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test-runner.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test-surface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test-texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test-window.cpp
    PARENT_SCOPE
)

set(TEST_HEADER_FILES
    ${TEST_HEADER_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/catch.hpp
    PARENT_SCOPE
)