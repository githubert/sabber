#include "echoreplier.h"

EchoReplier::EchoReplier(const QString& jid, const QString& password)
                            : client(std::unique_ptr<Client>(new Client(JID(jid.toUtf8().constData()),
                                                                        password.toUtf8().constData()))) {
    client->registerMessageSessionHandler(this, 0);
    client->setResource("sabber");
    this->start();
}

EchoReplier::~EchoReplier() {
    disposeCurrentSession();
    client->disconnect();
}

void EchoReplier::run() {
    client->connect();
}

void EchoReplier::disposeCurrentSession() {
    if(this->session) client->disposeMessageSession(this->session);
}

void EchoReplier::handleMessageSession(MessageSession* session) {
    disposeCurrentSession();
    session->registerMessageHandler(this);
    this->session = session;
}

void EchoReplier::handleMessage(const Message& message, MessageSession* session) {
    session->send(message.body());
}
