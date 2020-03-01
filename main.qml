import QtQuick 2.12
import QtQuick.Window 2.12
import TableModel 0.1

Window {
    visible: true
    width: 1080
    height: 720
    title: qsTr("Tools")

    TableView {
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        clip: true

        model: TableModel {}

        delegate: Rectangle {
            implicitWidth: 100
            implicitHeight: 50
            border.color : "black"
            border.width: 2
            color: (heading == true)?"green":"white"
            Text {
                text: tabledata
                font.pointSize: (heading == true)?16:12
                font.bold: heading
                anchors.centerIn: parent
            }
        }
    }
}

