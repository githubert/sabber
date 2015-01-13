cmake_minimum_required(VERSION 2.8.11)
project(sabber)

ADD_DEFINITIONS("-std=c++11")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)
include_directories(BEFORE ${QT_INCLUDES})
include_directories(qtquick2applicationviewer)
include_directories(src)

configure_file(qml/sabber/main.qml qml/sabber/main.qml)
configure_file(qml/sabber/conversationwindow.qml qml/sabber/conversationwindow.qml)

set(SOURCE_FILES
    qtquick2applicationviewer/qtquick2applicationviewer.cpp
    src/accountconfig.cpp
    src/connection.cpp
    src/conversation.cpp
    src/conversationwindow.cpp
    src/main.cpp
    src/windowmanager.cpp)

add_executable(sabber ${SOURCE_FILES})

target_link_libraries(sabber Qt5::Quick gloox)
