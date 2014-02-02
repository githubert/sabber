#include "accountconfig.h"

AccountConfig::AccountConfig(const QString& _name) : name(_name), settings("Sabber", "sabber") {
}

void AccountConfig::store() {
    inGroup([&]() {
            settings.setValue("jid", _jid);
            settings.setValue("password", _password);
        }, "accounts", name);
}

void AccountConfig::load() {
    inGroup([&]() {
                _jid = settings.value("jid").toString();
                _password = settings.value("password").toString();
            }, "accounts", name);
}

template<typename T, typename... Args> void AccountConfig::inGroup(T function, QString groupName, Args... groupNames) {
    settings.beginGroup(groupName);
    inGroup(function, groupNames...);
    settings.endGroup();
}

void AccountConfig::inGroup(std::function<void()> function) {
    function();
}

void AccountConfig::setJID(QString jid) {
    _jid = jid;
}

void AccountConfig::setPassword(QString password) {
    _password = password;
}
