#include "windowmanager.h"
#include "conversationwindow.h"

WindowManager::WindowManager(std::shared_ptr<QQmlEngine> engine) : engine(engine) {}

void WindowManager::newConversation(Conversation* conversation) {
    auto conversationWindow = new ConversationWindow(engine);

    QObject::connect(conversation, &Conversation::messageReceived,
                     conversationWindow->messageLogger());
    QObject::connect(conversationWindow, &ConversationWindow::closed, [=]() {
        delete conversation;
    });
}
