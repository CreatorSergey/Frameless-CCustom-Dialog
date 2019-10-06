#ifndef CSDIALOG_H
#define CSDIALOG_H

#include <QDialog>

/**
 * @brief Диалог
 */
class CCustomDialog: public QDialog
{
public:
    CCustomDialog(QWidget* parent, QWidget* content, const QString& title);
};

#endif // CSDIALOG_H
