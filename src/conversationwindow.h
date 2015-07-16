#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QObject>
#include <QQmlEngine>
#include <QString>

#include <forward_list>
#include <functional>
#include <memory>

class ConversationWindow : public QObject {
    Q_OBJECT

  public:
    ConversationWindow(std::shared_ptr<QQmlEngine> engine);
    std::function<void(const QString&)> messageLogger();

  public slots:
    void log(std::forward_list<QString> messages);

  signals:
    void closed();

  private:
    QObject* window;
};

#endif // CONVERSATIONWINDOW_H
