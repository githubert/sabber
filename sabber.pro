# Add more folders to ship with the application, here
folder_01.source = qml/sabber
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    accountconfig.cpp \
    connection.cpp \
    conversation.cpp \
    windowmanager.cpp \
    conversationwindow.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    accountconfig.h \
    connection.h \
    conversation.h \
    windowmanager.h \
    conversationwindow.h

LIBS += -lgloox

CONFIG += c++11

OTHER_FILES += \
    qml/sabber/conversationwindow.qml
