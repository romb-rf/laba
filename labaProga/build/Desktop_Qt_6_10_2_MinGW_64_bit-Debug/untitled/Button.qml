import QtQuick

Item {
    id: root;
    property alias text: buttonText.text
    property color color: "grey"


    signal clicked()

    Rectangle {
        property alias textColor: buttonText.color
        id: background
        anchors.fill: parent
        color: if (button1Area.containsPress){
                   return Qt.lighter(root.color)
               } else if (button1Area.containsMouse){
                   return Qt.darker(root.color)
               } else{
                   return root.color
               }
        border.color: "black"
        radius: 10


        Text{

            id: buttonText;

            anchors.centerIn: parent
            bottomPadding: 2

        }




    }
    anchors.centerIn: parent

    MouseArea{
        id: button1Area
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            root.clicked()

        }


    }

}
