cmake_minimum_required(VERSION 3.6.2)
project(sabber)

add_definitions("-std=c++11 -Wall")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fPIE -pie -fstack-protector-strong -D_FORTIFY_SOURCE=2")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

qt5_add_resources(Resources sabber.qrc)

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

set(CMAKE_SHARED_LINKER_FLAGS  "-Wl,-z,relro,-z,now -pie")
add_executable(sabber ${SOURCE_FILES} ${Resources})

target_link_libraries(sabber Qt5::Quick gloox)
