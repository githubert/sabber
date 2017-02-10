import QtQuick 2.7
import QtQuick.Window 2.2

Window {
  width: 360
  height: 360

  visible: true

  title: "chat window"

  ListModel {
    id: logModel
  }

  function log(author, message) {
    logModel.append({author: author, msg: message})
  }

  signal send(string msg)

  ListView {
    id: log;
    model: logModel
    anchors {
      top: parent.top
      bottom: input.top
    }
    visible: true
    delegate: Text {
      text: '<b>' + author + ':</b> ' + msg
    }
  }


  TextEdit {
    id: input;
    anchors {
      bottom: parent.bottom
    }
    font.pixelSize: 16
    height: 16
    width: parent.width
    focus: true
    wrapMode: TextEdit.WordWrap

    Keys.onReturnPressed: {
      if(input.text.length > 0) {
        send(input.text);
        logModel.append({author: "I", msg: input.text});
        input.text=""
      }
    }
  }
}
