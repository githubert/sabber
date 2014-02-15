# Add more folders to ship with the application, here
folder_01.source = qml/sabber
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    echoreplier.cpp \
    accountconfig.cpp \
    connection.cpp \
    conversation.cpp \
    conversationmanager.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    echoreplier.h \
    accountconfig.h \
    connection.h \
    conversation.h \
    conversationmanager.h

LIBS += -lgloox

CONFIG += c++11
