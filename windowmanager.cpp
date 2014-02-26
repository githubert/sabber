#include "windowmanager.h"
#include "conversationwindow.h"

WindowManager::WindowManager(std::shared_ptr<QQmlEngine> engine) : engine(engine) {}

void WindowManager::newConversation(std::shared_ptr<Conversation> conversation) {
    auto conversationWindow = new ConversationWindow(engine);

    QObject::connect(conversation.get(), &Conversation::messageReceived,
                     conversationWindow->messageLogger());
}
