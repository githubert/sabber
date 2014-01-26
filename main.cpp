#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>
#include "qtquick2applicationviewer.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine("qml/sabber/main.qml");

    return app.exec();
}
