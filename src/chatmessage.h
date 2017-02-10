#pragma once

#include <QtCore/QString>
#include <gloox/message.h>

class ChatMessage {
  public:
    ChatMessage(const gloox::Message& message);
    const QString author() const;
    const QString text() const;

  private:
    const gloox::Message& message;
};
