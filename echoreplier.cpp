#include "echoreplier.h"

void EchoReplier::messageReceived(const QString& message) {
    sendMessage(message);
}
