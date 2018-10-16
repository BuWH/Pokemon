cmake_minimum_required(VERSION 3.10)
project(Pokemon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.11.2/lib/cmake")

set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC on)
set(CMAKE_AUTORCC on)

find_package(Qt5 COMPONENTS Core Gui Widgets Network REQUIRED)

set(SOURCE_FILES main.cpp widget.cpp widget.h attacker.h basecreature.h attacker.cpp constdefine.h basecreature.cpp tanker.h widget.ui tanker.cpp defender.h defender.cpp assassin.cpp assassin.h user.h user.cpp creature.h creature.cpp)
add_executable(Pokemon ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Network)