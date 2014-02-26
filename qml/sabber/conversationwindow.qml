import QtQuick 2.0
import QtQuick.Window 2.1

Window {
    width: 360
    height: 360

    visible: true

    title: "Sabber – The Jabber Droolkit"

    ListModel {
        id: logModel
    }

    function log(message) {
        logModel.append({msg: message})
    }

    ListView {
        model: logModel
        anchors.fill: parent
        visible: true
        delegate: Text {
            text: msg
        }
    }
}
