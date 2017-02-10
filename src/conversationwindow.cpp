#include "conversationwindow.h"

ConversationWindow::ConversationWindow(std::shared_ptr<QQmlEngine> engine) {
  QQmlComponent component(engine.get(), QUrl("qrc:/qml/sabber/conversationwindow.qml"));
  if (component.isReady()) {
    window = std::unique_ptr<QQuickWindow>(qobject_cast<QQuickWindow *>(component.create()));
    window->installEventFilter(this);
    QObject::connect(window.get(), SIGNAL(send(QString)), this, SIGNAL(sendMessage(QString)));
  } else {
    qWarning() << component.errorString();
  }
}

std::function<void(const ChatMessage&)> ConversationWindow::messageLogger() {
  return [this](const ChatMessage& message) {
      QMetaObject::invokeMethod(window.get(), "log", Q_ARG(QVariant, message.author()), Q_ARG(QVariant, message.text()));
  };
}

bool ConversationWindow::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::Close) {
      closed();
  }
  return QObject::eventFilter(object, event);
}
