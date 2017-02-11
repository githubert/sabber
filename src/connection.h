#ifndef CONNECTION_H
#define CONNECTION_H

#include "accountconfig.h"
#include "conversation.h"

#include <gloox/message.h>
#include <gloox/client.h>
#include <gloox/messagesessionhandler.h>

#include <QtCore>

#include <memory>


using namespace gloox;

class Connection : public QThread, public MessageSessionHandler {
    Q_OBJECT

  public:
    Connection(const AccountConfig& config);
    ~Connection();
    void run();
    void handleMessageSession(MessageSession* session);

  signals:
    void newConversation(std::shared_ptr<Conversation>);

  private:
    const std::unique_ptr<Client> client;
};

#endif // CONNECTION_H
