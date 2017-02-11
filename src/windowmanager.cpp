#include "windowmanager.h"

WindowManager::WindowManager(QQmlEngine& engine) : engine(engine) {}

void WindowManager::newConversation(std::shared_ptr<Conversation> conversation) {
  const auto conversationWindow = new ConversationWindow(engine);

  auto loggingConnection = QObject::connect(conversation.get(), &Conversation::messageReceived,
                                            conversationWindow->messageLogger());
  auto sendConnection = QObject::connect(conversationWindow, &ConversationWindow::sendMessage,
                                        [conversation](const QString& message) {
                                          conversation->sendMessage(message);
                                        });
  QObject::connect(conversationWindow, &ConversationWindow::closed, [=]() {
    QObject::disconnect(loggingConnection);
    QObject::disconnect(sendConnection);
    conversationWindow->deleteLater();
    conversation.get(); // we just want to capture the shared_ptr
  });
}
