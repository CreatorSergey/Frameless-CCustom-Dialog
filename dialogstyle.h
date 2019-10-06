#ifndef DIALOGSTYLE_H
#define DIALOGSTYLE_H

constexpr const unsigned short HEADER_HEIGHT = 18;                          // Высота
constexpr const unsigned short HORRIZONTAL_MARGIN = 12;                     // Отступ
constexpr const char* CLOSE_ICON = ":/images/dialog_close_16.png";          // Иконка закрытия
constexpr const char* HEADER_COLOR = "background-color: black";             // Цвет
constexpr const char* CLOSE_BUTTON_HOVER_STYLE = "QToolButton:hover {background-color: rgba(255, 255, 255, 80)};"
                                                 "QToolButton:pressed {background-color: rgba(255, 255, 255, 140)};";

#endif // DIALOGSTYLE_H
