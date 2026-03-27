import QtQuick
import QtQuick.Controls 2.15
Item {

    anchors.fill: parent
    anchors.margins: 20
    Row {

        anchors.verticalCenter: parent.verticalCenter
        spacing: 50
        Text {
            id: introd
            text: "Введите текст:"
            font.pixelSize: 20
            font.bold: true


        }

           // Поле ввода
        TextInput {

            id: inputField

            width: 200
            height: 30
            font.pixelSize: 16
            color: "black"
            focus: true



            // Визуальное оформление
            Rectangle {
                x: -50
                anchors.fill: parent
                color: "transparent"
                border.color: "gray"
                border.width: 1
                radius: 10

            }

                // Сохраняем значение при изменении текста
            onTextChanged: {

            }

        }

        Text {
            // anchors.left: inputField.right
            text: "Вы ввели: " + dataM.userInput
            font.pixelSize: 16
            color: "black"
        }
    }
}

