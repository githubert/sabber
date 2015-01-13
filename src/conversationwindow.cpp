#include "conversationwindow.h"

#include <QQmlComponent>

ConversationWindow::ConversationWindow(std::shared_ptr<QQmlEngine> engine) {
    QString qmlFile("qml/sabber/conversationwindow.qml");
    auto component = new QQmlComponent(engine.get(), qmlFile);
    window = component->create();
    QObject::connect(component, &QQmlComponent::destroyed, this, &ConversationWindow::closed);
}

void ConversationWindow::log(std::forward_list<QString> messages) {
    std::for_each(messages.begin(), messages.end(), messageLogger());
}

std::function<void(const QString&)> ConversationWindow::messageLogger() {
    return [=](const QString& message) {
        QMetaObject::invokeMethod(window, "log", Q_ARG(QVariant, message));
    };
}
