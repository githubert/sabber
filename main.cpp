#include "qtquick2applicationviewer.h"
#include "accountconfig.h"
#include "connection.h"
#include "conversationmanager.h"

#include <QStringList>
#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <iostream>


int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    AccountConfig ac;
    ac.load();
    ac.store(); // just to end up with an empty .config/Sabber/sabber.conf file on the first run

    Connection connection(ac);
    ConversationManager conversationManager;

    qRegisterMetaType<std::shared_ptr<Conversation> >("std::shared_ptr<Conversation>");
    QObject::connect(&connection, SIGNAL(newConversation(std::shared_ptr<Conversation>)),
                     &conversationManager, SLOT(handleNewConversation(std::shared_ptr<Conversation>)),
                     Qt::DirectConnection);


    QQmlApplicationEngine engine;

    auto context = engine.rootContext();
    QStringList log;
    log << "foo" << "bar";
    context->setContextProperty("log", log);

    engine.load("qml/sabber/main.qml");

    return app.exec();
}
