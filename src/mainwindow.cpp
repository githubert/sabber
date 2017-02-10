#include <QDebug>
#include <QtQml/QQmlComponent>
#include <QtCore/QEvent>

#include "mainwindow.h"

MainWindow::MainWindow(QQmlEngine& engine) {
  QQmlComponent component(&engine, QUrl("qrc:/qml/sabber/main.qml"));
  if (component.isReady()) {
    window = std::unique_ptr<QObject>(component.create());
    window->installEventFilter(this);
  } else {
    qWarning() << component.errorString();
  }

}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
  if (event->type() == QEvent::Close) {
    closed();
  }
  return QObject::eventFilter(watched, event);
}
