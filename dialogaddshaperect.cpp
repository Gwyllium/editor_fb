

#include "dialogaddshaperect.h"
#include "ui_dialogaddshaperect.h"

DialogAddShapeRect::DialogAddShapeRect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddShapeRect)
{
    ui->setupUi(this);
}

DialogAddShapeRect::~DialogAddShapeRect()
{
    delete ui;
}

int DialogAddShapeRect::get_x()
{
    return ui->edit_xpos->text().toInt();
}
int DialogAddShapeRect::get_y()
{
    return ui->edit_ypos->text().toInt();
}

int DialogAddShapeRect::get_width()
{
    return ui->edit_width->text().toInt();
}

int DialogAddShapeRect::get_height()
{
    return ui->edit_height->text().toInt();
}

QString DialogAddShapeRect::get_name()
{
    return ui->edit_name->text();
}

void DialogAddShapeRect::setup(int x, int y, int width, int height, QString name)
{
    ui->edit_name->setText(name);
    ui->edit_xpos->setText(QString::number(x));
    ui->edit_ypos->setText(QString::number(y));

    ui->edit_width->setText(QString::number(width));
     ui->edit_height->setText(QString::number(height));
}
