import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: false
    title: qsTr("Hello World")


    Text {
        id: text1
        x: 0
        y: 0
        text: qsTr("Text")
        font.pixelSize: 12
    }
}
