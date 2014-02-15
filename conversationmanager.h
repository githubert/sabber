#ifndef CONVERSATIONMANAGER_H
#define CONVERSATIONMANAGER_H

#include "conversation.h"
#include "echoreplier.h"

#include <QtCore>

#include <memory>
#include <vector>

class ConversationManager : public QObject {
    Q_OBJECT

  public slots:
    void handleNewConversation(const std::shared_ptr<Conversation>& conversation);

  private:
    std::vector<std::shared_ptr<EchoReplier>> repliers;
};

#endif // CONVERSATIONMANAGER_H
