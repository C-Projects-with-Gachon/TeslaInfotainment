import QtQuick 2.12
import QtQuick.Window 2.12
import "ui/BottomBar"
import "ui/RightScreen"
import "ui/LeftScreen"

Window {
    visible: true
    width: 1280
    height: 720
    title: qsTr("Tesla Infotainmen")

    RightScreen {
        id:rightScreen
    }

    LeftScreen{
        id:leftScreen
    }

    BottomBar{
        id:bottomBar
    }
}
