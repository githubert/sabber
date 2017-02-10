#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QtQuick>

#include <memory>

#include "chatmessage.h"

class ConversationWindow : public QObject {
  Q_OBJECT

  public:
    ConversationWindow(std::shared_ptr<QQmlEngine> engine);
    bool eventFilter(QObject *object, QEvent *event);
    std::function<void(const ChatMessage&)> messageLogger();

  signals:
    void sendMessage(const QString& message);
    void closed();

  private:
    std::unique_ptr<QQuickWindow> window;
};
