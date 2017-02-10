#include <QDebug>
#include <QtQml/QQmlComponent>

#include "mainwindow.h"

MainWindow::MainWindow(std::shared_ptr<QQmlEngine> engine) {
  QQmlComponent component(engine.get(), QUrl("qrc:/qml/sabber/main.qml"));
  if (component.isReady()) {
    component.create();
  } else {
    qWarning() << component.errorString();
  }
}