#include "chatmessage.h"

ChatMessage::ChatMessage(const gloox::Message& message) : message(message) {};

const QString ChatMessage::author() const {
  return QString::fromUtf8(message.from().username().data());
}

const QString ChatMessage::text() const {
  return QString::fromUtf8(message.body().data());
}
