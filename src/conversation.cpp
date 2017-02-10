#include "conversation.h"

Conversation::Conversation(MessageSession *messageSession, std::function<void()> dispose) :
                                                                                    messageSession(messageSession),
                                                                                    dispose(dispose) {
  messageSession->registerMessageHandler(this);
}

Conversation::~Conversation() {
  dispose();
}

void Conversation::handleMessage(const Message &msg, MessageSession*) {
  messageReceived(ChatMessage(msg));
}

void Conversation::sendMessage(const QString &message) {
  messageSession->send(message.toUtf8().data());
}
