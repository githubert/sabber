#ifndef ACCOUNTCONFIG_H
#define ACCOUNTCONFIG_H

#include <gloox/jid.h>

#include <QSettings>
#include <QString>

class AccountConfig
{
public:
    AccountConfig(const QString& name = "default");
    void load();
    void store();
    QString password() const { return _password; }
    QString jid() const { return _jid; }
    void setPassword(QString password);
    void setJID(QString jid);

private:
    QString name;
    QString _jid;
    QString _password;
};

#endif // ACCOUNTCONFIG_H
