pragma Singleton
import QtQuick

QtObject {
    // Цвета светлой темы
    readonly property color lightBackground: "#f0f0ff"
    readonly property color lightText: "#202020"
    readonly property color lightButton: "#e0e0e0"
    readonly property color lightAccent: "#4285F4"

        // Цвета тёмной темы
    readonly property color darkBackground: "#303030"
    readonly property color darkText: "#f0f0f0"
    readonly property color darkButton: "#505050"
    readonly property color darkAccent: "#BB86FC"

        // Флаг темы
    property bool isLightTheme: true

        // Активные цвета, которые меняются при переключении
    readonly property color background: isLightTheme ? lightBackground : darkBackground
    readonly property color text: isLightTheme ? lightText : darkText
    readonly property color button: isLightTheme ? lightButton : darkButton
    readonly property color accent: isLightTheme ? lightAccent : darkAccent

        // Функция переключения
}
