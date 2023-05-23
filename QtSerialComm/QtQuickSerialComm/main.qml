import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.3
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")



    Button {
        id: changeStateButton
        x: 262
        y: 218
        width: 116
        height: 45
        text: qsTr("ChangeLedState")

        MouseArea {
            anchors.fill: parent
            onClicked: {
                arduino_blinker_state.switch_led_state()
            }
        }
    }


}
