#ifndef ECHOREPLIER_H
#define ECHOREPLIER_H

#include <QtCore>

class EchoReplier : public QObject {
    Q_OBJECT

  signals:
    void sendMessage(const QString& message);

  public slots:
    void messageReceived(const QString& message);
};

#endif // ECHOREPLIER_H
