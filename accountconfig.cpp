#include "accountconfig.h"

AccountConfig::AccountConfig(const QString& _name) : name(_name) {
}

void AccountConfig::store() {
    QSettings settings("Sabber", "sabber");

    settings.beginGroup("accounts");
    settings.beginGroup(name);

    settings.setValue("jid", _jid);
    settings.setValue("password", _password);
}

void AccountConfig::load() {
    QSettings settings("Sabber", "sabber");

    settings.beginGroup("accounts");
    settings.beginGroup(name);

    _jid = settings.value("jid").toString();
    _password = settings.value("password").toString();
}

void AccountConfig::setJID(QString jid) {
    _jid = jid;
}

void AccountConfig::setPassword(QString password) {
    _password = password;
}
