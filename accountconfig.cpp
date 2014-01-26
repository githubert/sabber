#include "accountconfig.h"

AccountConfig::AccountConfig(QString name)
{
    this->name = name;
}

void AccountConfig::store()
{
    QSettings settings("Sabber", "sabber");

    settings.beginGroup("accounts");
    settings.beginGroup(name);

    settings.setValue("jid", jid);
    settings.setValue("password", password);
}

void AccountConfig::load()
{
    QSettings settings("Sabber", "sabber");

    settings.beginGroup("accounts");
    settings.beginGroup(name);

    jid = settings.value("jid").toString();
    password = settings.value("password").toString();
}

QString AccountConfig::getPassword()
{
    return password;
}

QString AccountConfig::getJID()
{
    return jid;
}

void AccountConfig::setPassword(QString password)
{
    this->password = password;
}

void AccountConfig::setJID(QString jid)
{
    this->jid = jid;
}
