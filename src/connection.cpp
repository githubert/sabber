#include "connection.h"

Connection::Connection(const AccountConfig& config) :
  client(std::unique_ptr<Client>(new Client(JID(config.jid().toUtf8().constData()),
                                            config.password().toUtf8().constData()))) {
  client->registerMessageSessionHandler(this);
  client->setResource("sabber");
  this->start();
}

Connection::~Connection() {
  client->disconnect();
}

void Connection::run() {
  client->connect();
}

/**
 * The Conversation must be initialized in this method otherwise the first
 * message will be lost.
 */
void Connection::handleMessageSession(MessageSession *messageSession) {
  auto conversation = new Conversation(messageSession, [=]() {
    client->disposeMessageSession(messageSession);
  });
  newConversation(conversation); // needs to use a blocking connection!
}
