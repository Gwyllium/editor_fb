#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QList>
#include <QPoint>
#include <QCursor>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QMessageBox>




#include "dialogaddshaperect.h"

#include "editormovingobject.h"

#include "shape.h"
#include "noEditShape.h"




#include "standartpropertiestable.h"
#include "extendedpropertiestable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init_signalsEditorMovingObject(EditorMovingObject *obj);//метод для инициализации сигналов

    void init_scene();

    void delete_editorItem(EditorMovingObject *obj);



    virtual void keyPressEvent(QKeyEvent *event);

    QGraphicsScene scene;
    EditorMovingObject *selected_object;
    StandartPropertiesTable *tablprop;
    ExtendedPropertiesTable *extTablprop;
    
private slots:




    void slot_itemChanged(EditorMovingObject *obj, int type);

    void slot_itemDeleted(EditorMovingObject *obj);

    void slot_itemSelected(EditorMovingObject *obj);


    void on_btn_addnoEditShapeEllipse_clicked();
    void on_btn_addnoEditShapeRect_clicked();

private:
    Ui::MainWindow *ui;

protected:

};

#endif // MAINWINDOW_H
