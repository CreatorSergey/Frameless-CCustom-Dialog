#include "mainwindow.h"

#include <QApplication>

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

#include "ccustomdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel* label = new QLabel("Name:");
    QLineEdit* lineedit = new QLineEdit();

    QHBoxLayout *contentLayout = new QHBoxLayout();
    contentLayout->addWidget(label);
    contentLayout->addWidget(lineedit);

    QWidget* content = new QWidget();
    content->setLayout(contentLayout);

    CCustomDialog dialog(nullptr, content, "Example");
    dialog.show();

    return a.exec();
}
