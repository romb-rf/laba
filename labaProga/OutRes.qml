import QtQuick

Item {

    id: root
    property alias text: outText.text
    property color color: "white"
    Rectangle{
        id: out11
        color: "white"
        radius: 5
        border.color: "black"
        anchors.fill: parent

        Text{
            id: outText
            color: "black"
            anchors.centerIn: parent
            bottomPadding: 2
            text: "Результат"
        }

    }

}
