#ifndef ACCOUNTCONFIG_H
#define ACCOUNTCONFIG_H
#include <gloox/jid.h>
#include <QSettings>
#include <QString>

class AccountConfig
{
public:
    AccountConfig(QString name);
    void load();
    void store();
    QString getPassword();
    QString getJID();
    void setPassword(QString password);
    void setJID(QString jid);

private:
    QString name;
    QString jid;
    QString password;
};

#endif // ACCOUNTCONFIG_H
