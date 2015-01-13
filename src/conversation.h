#ifndef SESSION_H
#define SESSION_H

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
    void messageReceived(const QString &message);
    void messageLog(std::forward_list<QString> log);

  public slots:
    void sendMessage(const QString &message);

  private:
    MessageSession *messageSession;
    std::function<void()> dispose;
    std::forward_list<QString> messages;
};

#endif // SESSION_H
