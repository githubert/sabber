#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QtQuick>

#include <forward_list>
#include <functional>
#include <memory>

class ConversationWindow : public QObject {
  Q_OBJECT

  public:
    ConversationWindow(std::shared_ptr<QQmlEngine> engine);
    bool eventFilter(QObject *object, QEvent *event);
    std::function<void(const QString&)> messageLogger();

  public slots:
    void log(std::forward_list<QString> messages);

  signals:
    void sendMessage(const QString& message);
    void closed();

  private:
    std::unique_ptr<QQuickWindow> window;
};

#endif // CONVERSATIONWINDOW_H
