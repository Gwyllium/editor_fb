//диалог для создания нередактируемых объектов

#ifndef DIALOGADDSHAPERECT_H
#define DIALOGADDSHAPERECT_H

#include <QDialog>

namespace Ui {
class DialogAddShapeRect;
}

class DialogAddShapeRect : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogAddShapeRect(QWidget *parent = 0);
    ~DialogAddShapeRect();

    int get_x();
    int get_y();
    int get_width();
    int get_height();
    QString get_name();

    void setup(int x=0, int y=0, int width=100, int height=100, QString name="noname");

    
private:
    Ui::DialogAddShapeRect *ui;
};

#endif // DIALOGADDSHAPERECT_H
