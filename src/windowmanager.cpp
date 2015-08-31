#include "windowmanager.h"

WindowManager::WindowManager(std::shared_ptr<QQmlEngine> engine) : engine(engine) {}

void WindowManager::newConversation(Conversation* conversation) {
  auto conversationWindow = new ConversationWindow(engine);

  auto loggingConnection = QObject::connect(conversation, &Conversation::messageReceived,
                                            conversationWindow->messageLogger());
  QObject::connect(conversationWindow, &ConversationWindow::closed, [=]() {
    QObject::disconnect(loggingConnection);
    conversationWindow->deleteLater();
    delete conversation;
  });
}
