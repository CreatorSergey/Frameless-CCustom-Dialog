#include "ccustomdialogheader.h"

#include "dialogstyle.h"

#include <QMouseEvent>

/**
 * @brief Конструктор
 * @param parent - родитель
 * @param contol - объект, которым управлять
 */
CCustomDialogHeader::CCustomDialogHeader(QWidget* parent, QWidget* contol)
    : QLabel(parent)
    , mControl(contol)
{
    setFixedHeight(HEADER_HEIGHT);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    // Настройка цвета текста
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);
    setPalette(palette);
}

/**
 * @brief Нажатие мышью
 * @param event - событие
 */
void CCustomDialogHeader::mousePressEvent(QMouseEvent* event)
{
    mPress = event->pos();
    mPress.setX(mPress.x() + HORRIZONTAL_MARGIN);
}

/**
 * @brief Движение мышью
 * @param event - событие
 */
void CCustomDialogHeader::mouseMoveEvent(QMouseEvent* event)
{
    mControl->move(mapToGlobal(event->pos() - mPress));
}
