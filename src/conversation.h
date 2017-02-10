#pragma once

#include "chatmessage.h"
#include "conversationwindow.h"

#include <QtCore>

#include <gloox/messagehandler.h>
#include <gloox/messagesession.h>
#include <gloox/message.h>

#include <forward_list>
#include <functional>

using namespace gloox;

class Conversation : public QObject, public MessageHandler {
    Q_OBJECT

  public:
    Conversation(MessageSession *messageSession, std::function<void()> dispose);
    ~Conversation();
    void handleMessage(const Message &msg, MessageSession*);

  signals:
    void messageReceived(const ChatMessage &message);

  public slots:
    void sendMessage(const QString &message);

  private:
    MessageSession *messageSession;
    std::function<void()> dispose;
};
