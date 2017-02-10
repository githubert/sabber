#include "accountconfig.h"
#include "connection.h"
#include "mainwindow.h"
#include "windowmanager.h"

int main(int argc, char* argv[]) {
  QGuiApplication app(argc, argv);

  AccountConfig ac;
  ac.load();
  ac.store(); // just to end up with an empty .config/Sabber/sabber.conf file on the first run

  QQmlApplicationEngine engine;
  WindowManager windowManager(engine);
  Connection connection(ac);

  qRegisterMetaType<std::shared_ptr<Conversation>>("std::shared_ptr<Conversation>");
  QObject::connect(&connection, &Connection::newConversation,
                   &windowManager, &WindowManager::newConversation,
                   Qt::BlockingQueuedConnection);

  MainWindow mainWindow(engine);
  QObject::connect(&mainWindow, &MainWindow::closed, [&app]{app.quit();});

  return app.exec();
}
