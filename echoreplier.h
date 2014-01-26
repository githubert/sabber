#ifndef ECHOREPLIER_H
#define ECHOREPLIER_H

#include <gloox/message.h>
#include <gloox/client.h>
#include <gloox/messagesessionhandler.h>
#include <gloox/messagehandler.h>

#include <QtCore>

#include <memory>

using namespace gloox;

class EchoReplier : public MessageSessionHandler, public MessageHandler, public QThread {
  public:
    EchoReplier(const QString& jid, const QString& password);
    ~EchoReplier();
    void run();
    void handleMessageSession(MessageSession* session);
    void handleMessage(const Message& message, MessageSession* session);
  private:
    void disposeCurrentSession();
    const std::unique_ptr<Client> client;
    MessageSession* session;
};

#endif // ECHOREPLIER_H
