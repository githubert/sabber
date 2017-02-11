#pragma once

#include <conversation.h>

#include <QObject>
#include <QQmlEngine>

#include <memory>

class WindowManager : public QObject {
    Q_OBJECT

  public:
    WindowManager(QQmlEngine& engine);

  public slots:
    void newConversation(std::shared_ptr<Conversation> conversation);

  private:
    QQmlEngine& engine;
};

