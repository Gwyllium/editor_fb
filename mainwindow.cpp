#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowState(Qt::WindowMaximized);

    init_scene();

    selected_object=0;


       tablprop=new StandartPropertiesTable(ui->gvScene, this);
       tablprop->setGeometry(1010,70,250,200);




}

void MainWindow::init_scene()
{
    /*
     *Метод для инициализации сцены
     *сделан для уменьшения кода в конструкторе
     */
    ui->gvScene->setScene(&scene);

    //очерчиваем границы сцены
    QPen pen;
    pen.setWidth(5);
    pen.setStyle(Qt::DashDotLine);

    scene.addRect(0,0, 1024,768, pen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_signalsEditorMovingObject(EditorMovingObject *obj)
{
    /*
     *Метод для инициализации сигналов у объектов редактора
     */

    QObject::connect(obj, SIGNAL( signal_itemChanged(EditorMovingObject*, int)),
                          tablprop, SLOT(slot_itemChanged(EditorMovingObject*, int)));

    QObject::connect(tablprop, SIGNAL( signal_itemPosChanged(EditorMovingObject*, int, int)),
                          obj, SLOT(slot_itemPosChanged(EditorMovingObject*, int, int)));


    QObject::connect(obj, SIGNAL( signal_itemChanged(EditorMovingObject*, int)),
                          this, SLOT(slot_itemChanged(EditorMovingObject*, int)));

//    QObject::connect(this, SIGNAL( signal_itemPosChanged(EditorMovingObject*, int, int)),
//                          obj, SLOT(slot_itemPosChanged(EditorMovingObject*, int, int)));

    QObject::connect(obj, SIGNAL( signal_itemDeleted(EditorMovingObject*)),
                          this, SLOT(slot_itemDeleted(EditorMovingObject*)));

/*    QObject::connect(this, SIGNAL( signal_itemPosChanged(EditorMovingObject*, int, int)),
                          obj, SLOT(slot_itemPosChanged(EditorMovingObject*, int, int)));*/
}






void MainWindow::slot_itemChanged(EditorMovingObject *obj, int type)
{
    selected_object=obj;

}




void MainWindow::on_btn_addnoEditShapeRect_clicked()
{
    /*
     *Обработчик кнопки создания нередактируемого прямоугольника
     *
     */
    DialogAddShapeRect dlg;
    dlg.show();
    if(dlg.exec() == QDialog::Accepted)
        {
            //запрашиваем параметры
            int x=dlg.get_x();
            int y=dlg.get_y();

            int width=dlg.get_width();
            int height=dlg.get_height();
            QString name=dlg.get_name();


            //создаем объект и добавляем его на сцену
            noEditShape *mo=new noEditShape(1, x,y,width, height, name);
            init_signalsEditorMovingObject(mo);
            scene.addItem(mo);
        }

}


void MainWindow::on_btn_addnoEditShapeEllipse_clicked()
{
    /*
     *Обработчик кнопки создания нередактируемого эллипса
     *
     */
    DialogAddShapeRect dlg;
    dlg.show();
    if(dlg.exec() == QDialog::Accepted)
        {
        //запрашиваем параметры из диалона
            int x=dlg.get_x();
            int y=dlg.get_y();

            int width=dlg.get_width();
            int height=dlg.get_height();
            QString name=dlg.get_name();


            //создаем объект и добавляем его на сцену
            noEditShape *mo=new noEditShape(2, x,y,width, height, name);
            init_signalsEditorMovingObject(mo);
            scene.addItem(mo);
        }
}

void MainWindow::delete_editorItem(EditorMovingObject *obj)
{
    QMessageBox msgbox(QMessageBox::Question, "Удаление объекта", "Вы действительно хотите удалить объект?",
                       QMessageBox::Yes|QMessageBox::No);

    int result=msgbox.exec();

    if (result==QMessageBox::Yes)
    {

    scene.removeItem(selected_object);
    selected_object=0;
    delete obj;

    tablprop->reset_selection();
    }
}

void MainWindow::slot_itemDeleted(EditorMovingObject *obj)
{
   delete_editorItem(selected_object);
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();

    if((key==Qt::Key_Delete)&&(selected_object!=0))
    {
        delete_editorItem(selected_object);
    }
}

void MainWindow::slot_itemSelected(EditorMovingObject *obj)
{
    selected_object=obj;


}

