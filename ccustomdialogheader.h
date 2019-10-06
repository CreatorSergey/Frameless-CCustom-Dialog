#ifndef CSHEADER_H
#define CSHEADER_H

#include <QLabel>

/**
 * @brief Заголовок диалога
 */
class CCustomDialogHeader: public QLabel
{
public:
    CCustomDialogHeader(QWidget* parent, QWidget* contol);

protected:
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;

protected:
    QWidget* mControl = nullptr;    // Объект, кого будем двигать
    QPoint mPress;                  // Позиция нажатия
};

#endif // CSHEADER_H
