#include "qtquick2applicationviewer.h"
#include "accountconfig.h"
#include "connection.h"
#include "windowmanager.h"

#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    AccountConfig ac;
    ac.load();
    ac.store(); // just to end up with an empty .config/Sabber/sabber.conf file on the first run

    auto engine = std::make_shared<QQmlApplicationEngine>();

    WindowManager windowManager(engine);
    Connection connection(ac);

    qRegisterMetaType<std::shared_ptr<Conversation> >("std::shared_ptr<Conversation>");
    QObject::connect(&connection, &Connection::newConversation,
                     &windowManager, &WindowManager::newConversation,
                     Qt::BlockingQueuedConnection);


    engine->load("qml/sabber/main.qml");

    return app.exec();
}