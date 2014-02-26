#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QObject>
#include <QQmlEngine>
#include <QString>

#include <forward_list>

class ConversationWindow : public QObject {
    Q_OBJECT

  public:
    ConversationWindow(std::shared_ptr<QQmlEngine> engine);
    std::function<void(const QString&)> messageLogger();
    void loadLog();

  public slots:
    void log(std::forward_list<QString> messages);

  private:
    QObject* window;
};

#endif // CONVERSATIONWINDOW_H
