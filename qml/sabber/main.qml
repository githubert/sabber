import QtQuick 2.0
import QtQuick.Controls 1.1

ApplicationWindow {
    width: 360
    height: 360
    visible: true

    title: "Sabber – The Jabber Droolkit"

    Text {
        id: text
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
