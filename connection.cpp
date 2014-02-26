#include "connection.h"

Connection::Connection(const AccountConfig& config) :
    client(std::unique_ptr<Client>(new Client(JID(config.jid().toUtf8().constData()),
                                              config.password().toUtf8().constData()))) {
    client->registerMessageSessionHandler(this, 0);
    client->setResource("sabber");
    this->start();
}

Connection::~Connection() {
    sessions.clear();
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
    std::shared_ptr<Conversation> conversation(new Conversation(messageSession, [&]() {
        client->disposeMessageSession(messageSession);
    }));
    sessions.push_back(conversation);
    newConversation(conversation); // needs to use a blocking connection!
}
