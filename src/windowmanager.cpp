#include "windowmanager.h"

WindowManager::WindowManager(QQmlEngine& engine) : engine(engine) {}

void WindowManager::newConversation(Conversation* conversation) {
  auto conversationWindow = new ConversationWindow(engine);

  auto loggingConnection = QObject::connect(conversation, &Conversation::messageReceived,
                                            conversationWindow->messageLogger());
  auto sendConnection = QObject::connect(conversationWindow, &ConversationWindow::sendMessage,
                                        [=](const QString& message) {
                                          conversation->sendMessage(message);
                                        });
  QObject::connect(conversationWindow, &ConversationWindow::closed, [=]() {
    QObject::disconnect(loggingConnection);
    QObject::disconnect(sendConnection);
    conversationWindow->deleteLater();
    delete conversation;
  });
}
