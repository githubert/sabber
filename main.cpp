#include "echoreplier.h"
#include "qtquick2applicationviewer.h"
#include "accountconfig.h"

#include <iostream>

#include <QStringList>
#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    AccountConfig ac;
    ac.load();
    ac.store(); // just to end up with an empty .config/Sabber/sabber.conf file on the first run

    std::cout << "connecting jid " << ac.jid().toUtf8().constData() << std::endl;
    EchoReplier replier(ac.jid(), ac.password());

    QQmlApplicationEngine engine;

    auto context = engine.rootContext();
    QStringList log;
    log << "foo" << "bar";
    context->setContextProperty("log", log);

    engine.load("qml/sabber/main.qml");

    return app.exec();
}
