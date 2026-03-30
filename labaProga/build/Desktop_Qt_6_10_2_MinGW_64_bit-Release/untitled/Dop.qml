import QtQuick
import QtQuick.Window
import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
Window {
    id: secondWindow
    width: 450
    height: 500
    title: "Дополнительное задание"
    visible: false
    modality: Qt.NonModal

    //анимация появления
    NumberAnimation on opacity {
        id: appearAnimation
        from: 0
        to: 1
        duration: 200
        running: false
    }

    onVisibleChanged: {
        if (visible) {
            opacity = 0
            appearAnimation.start()
        }
    }
    Rectangle {
        anchors.fill: parent
        anchors.margins: 25
        color: "transparent"

        ColumnLayout {
            spacing: 25
            anchors.fill: parent
            RowLayout {
                Layout.fillWidth: true

                Text {
                    text: "Простые делители"
                    font.pixelSize: 32
                    font.bold: true
                    color: "#2c3e50"
                }
                Item { Layout.fillWidth: true }
            }
            Rectangle {
                Layout.fillWidth: true
                height: 100
                color: "#1e000000"
                radius: 16
                Row {
                    anchors.verticalCenter: parent.verticalCenter
                    spacing: 50
                    TextField {
                        id: inputField
                        placeholderText: "Введите число"
                        width: 200
                        height: 40

                        background: Rectangle {
                            radius: 10
                            border.color: {
                                if (inputField.text === "") return "gray"
                                if (validator.checkInt(inputField.text)) return "green"
                                return "red"
                            }
                            border.width: 1
                            color: "white"
                        }
                        color: "black"
                        onEditingFinished: {
                            validator.clearError()
                            if (validator.checkInt(text)) {
                                dataM.saveData(text)
                            }
                        }

                    }
                    Text {
                        id: errorText
                        color: "red"
                        text: validator.lastError
                    }

                    Text {
                        text: "Вы ввели: " + dataM.userInput
                        font.pixelSize: 16
                        color: "black"
                    }
                }
            }
            //Выполнить и результат
            ColumnLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: 120
                spacing: 25
                anchors.verticalCenter: secondWindow

                Rectangle {
                    width: 400
                    height: 70
                    radius: 16
                    layer.enabled: true

                    CastomButton{
                        anchors.centerIn: parent
                        text: "Выполнить"
                        fontSize: 28
                        fontBold: true
                        textColor: "black"
                        onClicked: {
                            validator.clearError()
                            validator.checkInt(inputField.text)
                            if (validator.checkInt(inputField.text)){

                                dataM.saveData(inputField.text)
                                dop.calculate(dataM.userInput)
                            }

                        }
                    }
                }
                Text {
                    text: "Результат " + dop.res
                    font.pixelSize: 32
                    font.bold: true
                    color: "#27ae60"
                }
            }
            Item { Layout.fillHeight: true }
        }
    }
    Button {
        text: "Закрыть"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: secondWindow.close()
    }
}
