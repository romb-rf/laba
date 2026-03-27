import QtQuick

Item {

    id: root
    property alias text: "Результат"
    property color color: "white"
    Rectangle{
        id: outRes

        radius: 5
        border.color: "black"
        anchors.fill: parent

        Text{
            id: outText
            color: "black"
            anchors.centerIn: parent
            bottomPadding: 2
        }

    }
    anchors.top: parent
}
