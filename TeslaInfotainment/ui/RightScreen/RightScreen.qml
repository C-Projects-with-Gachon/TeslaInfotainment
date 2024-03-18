import QtQuick 2.0
import QtLocation 5.12
import QtPositioning 5.12

Rectangle {
    id: rightScreen

    anchors{
        top: parent.top
        bottom: bottomBar.top
        right: parent.right
    }
    Plugin{
            id:mapPlugin
            name: "mapboxgl"
        }
        Map{
            anchors.fill:parent
            plugin: mapPlugin
            center:QtPositioning.coordinate(37.56, 126.97) //seoul
            zoomLevel: 14
        }

        Image {
            id: lockIcon
            anchors{
                left: parent.left
                top: parent.top
                margins:20
            }
            width: parent.width / 40
            fillMode: Image.PreserveAspectFit
            source: ( systemHandler.carLocked ? "qrc:/ui/assets/lock.png" : "qrc:/ui/assets/unlock.png" )
            MouseArea{
                anchors.fill : parent
                onClicked: systemHandler.setCarLocked(!systemHandler.carLocked)
            }
        }

        Text {
            id: dateTimeDisplay
            anchors {
                left: lockIcon.right
                leftMargin: 40
                bottom: lockIcon.bottom
            }
            font.pixelSize: 14
            font.bold: true
            color:"black"

            text: systemHandler.currentTime
        }
        Text {
            id: outdoorTemperaturDisplay
            anchors {
                left: dateTimeDisplay.right
                leftMargin: 40
                bottom: lockIcon.bottom
            }
            font.pixelSize: 12
            font.bold: true
            color:"black"

            text: systemHandler.outdoorTemp+"°F"
        }
        Text {
            id: userNameDisplay
            anchors {
                left: outdoorTemperaturDisplay.right
                leftMargin: 40
                bottom: lockIcon.bottom
            }
            font.pixelSize: 12
            font.bold: true
            color:"black"

            text: systemHandler.userName
        }
        NavigationSearchBox{
            id: navSearchBox

            width: parent.width * 1/3
            height: parent.height * 1/12
            anchors{
                left: lockIcon.left
                top: lockIcon.bottom
                topMargin: 15
            }
        }

    width: parent.width * 2/3
}
