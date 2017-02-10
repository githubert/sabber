import QtQuick.Window 2.2
import QtQuick.Controls 2.0

ApplicationWindow {
    width: 200
    height: 360
    visible: true

    Button {
        text: "MUC"
        width: parent.width
        onClicked: mucSelector.open()
    }

    signal mucOpen(string muc)

    Popup {
        id: mucSelector
        width: parent.width
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape

        TextField {
            id: mucChoice
            height: parent.height
            width: parent.width
            focus: true

            onAccepted: {
                if(mucChoice.text.length > 0) {
                    mucOpen(mucChoice.text);
                    mucSelector.close();
                }
            }
        }
    }

    title: "Sabber – The Jabber Droolkit"
}

