#include "conversation.h"

Conversation::Conversation(MessageSession *messageSession, std::function<void()> dispose) : messageSession(messageSession), dispose(dispose) {}

Conversation::~Conversation() {
    dispose();
}

void Conversation::handleMessage(const Message &msg, MessageSession*) {
    if(msg.body().length() > 0) {
        messageReceived(QString::fromUtf8(msg.body().data()));
    }
}

void Conversation::sendMessage(const QString& message) {
    messageSession->send(message.toUtf8().data());
}
