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
    MessageSession* session;

    void disposeCurrentSession();
    const std::unique_ptr<Client> client;
};

#endif // ECHOREPLIER_H
