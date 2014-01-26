#include "echoreplier.h"
#include "qtquick2applicationviewer.h"

#include <iostream>
#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cout << "usage: sabber <JID> <password>" << std::endl;
        return 1;
    }

    QGuiApplication app(argc, argv);
    EchoReplier replier(argv[1], argv[2]);

    QQmlApplicationEngine engine("qml/sabber/main.qml");
    return app.exec();
}
