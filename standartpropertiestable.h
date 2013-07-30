#ifndef STANDARTPROPERTIESTABLE_H
#define STANDARTPROPERTIESTABLE_H

#include <QTableWidget>
#include <QHeaderView>
#include <QGraphicsView>

#include <QColorDialog>
#include <QPushButton>

#include "editormovingobject.h"

class StandartPropertiesTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit StandartPropertiesTable(QGraphicsView *gw, QWidget *parent = 0);

    EditorMovingObject *selected_object;

    QGraphicsView *gw;

    void reset_selection();// вызывается при удалении объекта. В таблице обнуляются значения


    
signals:
    void signal_itemPosChanged(EditorMovingObject *obj, int x, int y);
    void signal_itemNameChanged(EditorMovingObject *obj, QString name);
    
public slots:
    void slot_itemChanged(EditorMovingObject *obj, int type);

    void cellChanged(int row, int column);

    void cellActivated(int row, int column);
    
};

#endif // STANDARTPROPERTIESTABLE_H
