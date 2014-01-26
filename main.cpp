#include "echoreplier.h"
#include "qtquick2applicationviewer.h"
#include "accountconfig.h"

#include <iostream>
#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
    AccountConfig ac;
    ac.load();
    ac.store(); // just to end up with an empty .config/Sabber/sabber.conf file

    QGuiApplication app(argc, argv);
    EchoReplier replier(ac.jid(), ac.password());

    QQmlApplicationEngine engine("qml/sabber/main.qml");
    return app.exec();
}
