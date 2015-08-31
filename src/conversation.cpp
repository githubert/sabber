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
  const QString text = QString::fromUtf8(msg.body().data());
  messages.push_front(text);
  messageReceived(text);
}

void Conversation::sendMessage(const QString &message) {
  messageSession->send(message.toUtf8().data());
}
