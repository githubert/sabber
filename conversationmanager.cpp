#include "conversationmanager.h"

void ConversationManager::handleNewConversation(const std::shared_ptr<Conversation>& conversation) {
    std::shared_ptr<EchoReplier> replier(new EchoReplier());
    QObject::connect(replier.get(), SIGNAL(sendMessage(const QString&)),
                     conversation.get(), SLOT(sendMessage(const QString&)),
                     Qt::DirectConnection);
    QObject::connect(conversation.get(), SIGNAL(messageReceived(const QString&)),
                     replier.get(), SLOT(messageReceived(const QString&)));
    repliers.push_back(replier);
}
