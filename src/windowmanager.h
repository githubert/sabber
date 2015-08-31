#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <conversation.h>

#include <QObject>
#include <QQmlEngine>

#include <memory>

class WindowManager : public QObject {
    Q_OBJECT

  public:
    WindowManager(std::shared_ptr<QQmlEngine> engine);

  public slots:
    void newConversation(Conversation* conversation);

  private:
    void cleanUp();

    std::shared_ptr<QQmlEngine> engine;
    QMetaObject::Connection logging;
};

#endif // WINDOWMANAGER_H
