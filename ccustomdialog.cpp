#include "ccustomdialog.h"

#include "ccustomdialogheader.h"
#include "dialogstyle.h"

#include <QHBoxLayout>
#include <QSizeGrip>
#include <QToolButton>
#include <QDialogButtonBox>

/**
 * @brief Конструктор
 * @param parent - родитель
 * @param content - виджет содержимого
 * @param title - заголовок
 */
CCustomDialog::CCustomDialog(QWidget* parent, QWidget* content, const QString& title)
    : QDialog(parent, Qt::FramelessWindowHint)
{
    // Заголовок
    CCustomDialogHeader* header = new CCustomDialogHeader(nullptr, this);
    header->setText(title);

    // Кнопка закрытия
    QToolButton* close = new QToolButton();
    close->setIcon(QIcon(CLOSE_ICON));
    close->setStyleSheet(CLOSE_BUTTON_HOVER_STYLE);
    QObject::connect(close, &QToolButton::clicked, this, &QDialog::close);

    // Разметка заголовка
    QSpacerItem* spacer = new QSpacerItem(1, 1, QSizePolicy::Maximum, QSizePolicy::Fixed);
    QHBoxLayout* headerLayout = new QHBoxLayout();
    headerLayout->addWidget(header);
    headerLayout->addSpacerItem(spacer);
    headerLayout->addWidget(close);
    headerLayout->setContentsMargins(HORRIZONTAL_MARGIN, 0, 0, 0);

    // Виджет заголовка
    QWidget* headerFull = new QWidget();
    headerFull->setLayout(headerLayout);
    headerFull->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    headerFull->setStyleSheet(HEADER_COLOR);

    // Рукоятка изменения размера
    QSizeGrip * sizeGrip = new QSizeGrip(this);

    // Набор стандартных кнопок
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    // Разметка кнопок
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(buttonBox);
    buttonsLayout->setContentsMargins(HORRIZONTAL_MARGIN, 0, HORRIZONTAL_MARGIN, 0);

    // Виджет кнопок
    QWidget* buttons = new QWidget();
    buttons->setLayout(buttonsLayout);

    // Отделитель подвала
    QSpacerItem* spacerFooter = new QSpacerItem(1, 1, QSizePolicy::Fixed, QSizePolicy::Expanding);

    // Финальная разметка
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(headerFull, 0, Qt::AlignTop);
    layout->addWidget(content, 0, Qt::AlignTop);
    layout->addSpacerItem(spacerFooter);
    layout->addWidget(buttons, 0, Qt::AlignBottom | Qt::AlignRight);
    layout->addWidget(sizeGrip, 0, Qt::AlignBottom | Qt::AlignRight);

    setLayout(layout);
}
