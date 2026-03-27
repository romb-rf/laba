import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls           // для ApplicationWindow (опционально)
import Qt5Compat.GraphicalEffects         // для DropShadow

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 900
    height: 900
    title: "Лабораторная работа"
    background: Rectangle { color: "#f5f5f5" }
    property var n
    n: ""
    // Основной контейнер с отступами
    Rectangle {
        anchors.fill: parent
        anchors.margins: 25
        color: "transparent"

        ColumnLayout {
            spacing: 25
            anchors.fill: parent

            // Верхняя строка: заголовок и результат
            RowLayout {
                Layout.fillWidth: true

                Text {
                    text: "Рекурсия VS Итерация"
                    font.pixelSize: 32
                    font.bold: true
                    color: "#2c3e50"
                }

                Item { Layout.fillWidth: true }  // растяжка


            }
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                color: "white"
                radius: 16
                layer.enabled: true
                layer.effect: DropShadow {
                    transparentBorder: true
                    horizontalOffset: 0
                    verticalOffset: 4
                    radius: 12
                    samples: 24
                    color: "#1e000000"
                }

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 12

                    Text {
                        id: choiceForm
                        text: "Выбор формулы:"
                        font.pixelSize: 20
                        font.bold: true
                        color: "#34495e"
                    }
                    anchors.top: choiceForm.bottom
                    anchors.left: parent.left

                    ComboBox {
                        id: comboBox


                        model: ["           F(n) = 1, при n <= 1; \n
            F(n) = 4 * n + F(n - 1) - F(2), если n>1 и при этом n нечётно;\n
            F(n) = 3 * F(n - 1), если n > 1 и при этом n чётно.",
                                    "            F(n) = 1, при n = 1;\n
            F(n) = 2, при n = 2;\n
            F(n) = [(7*n + F(n - 3))/9], если n > 2 и при этом n четно\n
            F(n) = [(5*n + F(n - 1) + F(n - 2))/7], если n > 2 и при этом n нечетно\n"]
                        contentItem: Text {
                            text: parent.displayText
                            font: parent.font
                            color: "black"               // цвет текста
                            verticalAlignment: Text.AlignVCenter
                            leftPadding: 10
                        }
                        onActivated: (index) => {
                            recVar.onComboIndexChanged(index);
                            iter.onComboIndexChanged(index);

                        }
                    }
                }
            }

            //ввод значения
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
                        // anchors.left: inputField.right
                        text: "Вы ввели: " + dataM.userInput
                        font.pixelSize: 16
                        color: "black"
                    }
                }


            }
            //Выполнить и результат
            RowLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: 120
                spacing: 25

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
                            }


                            recVar.calculate(dataM.userInput)
                            iter.calculate(dataM.userInput)





                        }

                    }


                }

                Text {
                    text: "Результат " + iter.result
                    font.pixelSize: 32
                    font.bold: true
                    color: "#27ae60"
                }


            }

            // Карточка с таблицей сравнения
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 240
                color: "white"
                radius: 16
                layer.enabled: true
                layer.effect: DropShadow {
                    transparentBorder: true
                    horizontalOffset: 0
                    verticalOffset: 4
                    radius: 12
                    samples: 24
                    color: "#1e000000"
                }

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 16

                    Text {
                        text: "Сравнение итеративного и рекурсивного"
                        font.pixelSize: 20
                        font.bold: true
                        color: "#34495e"
                    }

                    // Таблица 3x4 (включая заголовок)
                    GridLayout {
                        columns: 3
                        columnSpacing: 30
                        rowSpacing: 12
                        Layout.fillWidth: true

                        // Пустая ячейка в углу
                        Item { Layout.preferredWidth: 140 }

                        Text {
                            text: "Рекурсия"
                            font.bold: true
                            color: "#2980b9"
                            font.pixelSize: 16
                        }
                        Text {
                            text: "Итерация"
                            font.bold: true
                            color: "#2980b9"
                            font.pixelSize: 16
                        }

                        // Строка 1: Шаги
                        Text {
                            text: "Шаги / Вызовы"
                            color: "#7f8c8d"
                            font.pixelSize: 15
                        }
                        Text {
                            text: recVar.callCnt
                            color: "#2c3e50"
                            font.bold: true
                            font.pixelSize: 16
                        }
                        Text {
                            text: iter.callCnt
                            color: "#2c3e50"
                            font.bold: true
                            font.pixelSize: 16
                        }

                        // Строка 2: Время
                        Text {
                            text: "Время выполнения"
                            color: "#7f8c8d"
                            font.pixelSize: 15
                        }
                        Text {
                            text: recVar.cnt + " ns"
                            color: "#2c3e50"
                            font.pixelSize: 16
                        }
                        Text {
                            text: iter.cnt + " ns"
                            color: "#2c3e50"
                            font.pixelSize: 16
                        }

                        // Строка 3: Память
                        Text {
                            text: "Память"
                            color: "#7f8c8d"
                            font.pixelSize: 15
                        }
                        Text {
                            text: "1008 B (Stack)"
                            color: "#2c3e50"
                            font.pixelSize: 16
                        }
                        Text {
                            text: "560 B (Heap)"
                            color: "#2c3e50"
                            font.pixelSize: 16
                        }
                    }
                }
            }


            Item { Layout.fillHeight: true }
        }
    }
}
