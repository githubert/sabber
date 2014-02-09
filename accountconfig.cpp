#include "accountconfig.h"

namespace {
    const QString ACCOUNT_GROUP_NAME = "accounts";
    const QString JID_FIELD_NAME = "jid";
    const QString PASSWORD_FIELD_NAME = "password";
}


AccountConfig::AccountConfig(const QString& _name) : name(_name), settings("Sabber", "sabber") {
}

void AccountConfig::store() {
    inGroup([&]() {
                settings.setValue(JID_FIELD_NAME, _jid);
                settings.setValue(PASSWORD_FIELD_NAME, _password);
            }, ACCOUNT_GROUP_NAME, name);
}

void AccountConfig::load() {
    inGroup([&]() {
                _jid = settings.value(JID_FIELD_NAME).toString();
                _password = settings.value(PASSWORD_FIELD_NAME).toString();
            }, ACCOUNT_GROUP_NAME, name);
}

template<typename T, typename... Args> void AccountConfig::inGroup(T function, const QString& groupName, const Args&... groupNames) {
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
