cmake_minimum_required(VERSION 3.10)
project(Pokemon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.11.2/lib/cmake")

set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC on)
set(CMAKE_AUTORCC on)

find_package(Qt5 COMPONENTS Core Gui Sql Widgets Network REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/fight
        ${PROJECT_SOURCE_DIR}/singlecreature
        ${PROJECT_SOURCE_DIR}/login

)

file(GLOB SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/singlecreature/*.h"
        "${PROJECT_SOURCE_DIR}/singlecreature/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/fight/*.h"
        "${PROJECT_SOURCE_DIR}/fight/*.cpp"
        "${PROJECT_SOURCE_DIR}/login/*.h"
        "${PROJECT_SOURCE_DIR}/login/login.cpp"
        "${PROJECT_SOURCE_DIR}/*.h"
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )

add_executable(Pokemon ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Sql Qt5::Network)