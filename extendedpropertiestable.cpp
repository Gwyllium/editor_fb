#include "extendedpropertiestable.h"

ExtendedPropertiesTable::ExtendedPropertiesTable(QWidget *parent):
    QTableWidget(parent)
{
    setRowCount(4);
    setColumnCount(2);

    QStringList listNames;
    listNames<<"Свойство"<<"Параметры";

    setHorizontalHeaderLabels(listNames);

   // this->verticalHeader()->hide();

    setItem(0,0,new QTableWidgetItem("name"));
    setItem(1,0,new QTableWidgetItem("x"));
    setItem(2,0,new QTableWidgetItem("y"));
}
