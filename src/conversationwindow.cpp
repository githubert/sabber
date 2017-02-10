#include "conversationwindow.h"

ConversationWindow::ConversationWindow(std::shared_ptr<QQmlEngine> engine) {
  QQmlComponent component(engine.get(), QUrl("qml/sabber/conversationwindow.qml"));
  window = std::unique_ptr<QQuickWindow>(qobject_cast<QQuickWindow*>(component.create()));
  window->installEventFilter(this);

  QObject::connect(window.get(), SIGNAL(send(QString)), this, SIGNAL(sendMessage(QString)));
}

void ConversationWindow::log(std::forward_list<QString> messages) {
  std::for_each(messages.begin(), messages.end(), messageLogger());
}

std::function<void(const QString&)> ConversationWindow::messageLogger() {
  return [=](const QString& message) {
      QMetaObject::invokeMethod(window.get(), "log", Q_ARG(QVariant, message));
  };
}

bool ConversationWindow::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::Close) {
      closed();
  }
  return QObject::eventFilter(object, event);
}
