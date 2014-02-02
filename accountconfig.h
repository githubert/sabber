#ifndef ACCOUNTCONFIG_H
#define ACCOUNTCONFIG_H

#include <gloox/jid.h>

#include <QSettings>
#include <QString>

#include <functional>

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
    QSettings settings;
    QString _jid;
    QString _password;

    template<typename T, typename... Args> void inGroup(T function, QString groupName, Args... groupNames);
    void inGroup(std::function<void()> function);
};

#endif // ACCOUNTCONFIG_H
