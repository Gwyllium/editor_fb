#include "standartpropertiestable.h"

StandartPropertiesTable::StandartPropertiesTable (QGraphicsView *gw, QWidget *parent) :
    QTableWidget(parent)
{
    setRowCount(4);
    setColumnCount(2);
    this->gw=gw;

    QStringList listNames;
    listNames<<"Свойство"<<"Параметры";

    setHorizontalHeaderLabels(listNames);

    this->verticalHeader()->hide();

    setItem(0,0,new QTableWidgetItem("name"));
    setItem(1,0,new QTableWidgetItem("x"));
    setItem(2,0,new QTableWidgetItem("y"));

    setItem(3,0,new QTableWidgetItem("Толщина линии"));
    setItem(4,0,new QTableWidgetItem("Цвет линии"));

     QPushButton *btn = new QPushButton("Download");

    setCellWidget(4,1,btn);


    QObject::connect(this, SIGNAL( cellChanged(int,int)),
                     this, SLOT(cellChanged(int , int)));
}


void StandartPropertiesTable::slot_itemChanged(EditorMovingObject *obj, int type)
{
    //qDebug()<<"Таблица получила сообщение: "<<obj->pos().x();
     QObject::blockSignals ( true);

    selected_object=obj;


    int x=obj->pos().x();
    int y=obj->pos().y();

     setItem(0,1, new  QTableWidgetItem(obj->name));
    setItem(1,1, new  QTableWidgetItem(QString::number(x)));
    setItem(2,1, new  QTableWidgetItem(QString::number(y)));
     QObject::blockSignals ( false);
}

void StandartPropertiesTable::cellChanged(int row, int column)
{

    int x=item(1,1)->data(Qt::DisplayRole).toInt();
    int y=item(2,1)->data(Qt::DisplayRole).toInt();
     qDebug()<<x<<y;
    QString name=item(0,1)->data(Qt::DisplayRole).toString();



    selected_object->name=name;

    QPointF p=gw->mapFromScene(x,y);
     emit signal_itemPosChanged(selected_object, p.x(), p.y());

}

void StandartPropertiesTable::reset_selection()
{
    selected_object=0;
    QObject::blockSignals(true);
    setItem(0,1, new  QTableWidgetItem(""));
    setItem(1,1, new  QTableWidgetItem(""));
    setItem(2,1, new  QTableWidgetItem(""));
    QObject::blockSignals(false);

}

void StandartPropertiesTable::cellActivated(int row, int column)
{
    if ((row==4)&&(column==1))
    {
        QColorDialog::getColor();
    }
}
