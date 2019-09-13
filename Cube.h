#ifndef CUBE_H
#define CUBE_H

#include <QLabel>
#include <QWidget>
#include <iostream>
class Cube : public QWidget
{
    Q_OBJECT
public:
    explicit Cube(QWidget *parent = nullptr);
    void setLetter(QString l);
    void setXY(int x,int y ){
        this->x=x;
        this->y=y;
    }
    void  setBlack();
    void  setYellow();

    void  mousePressEvent(QMouseEvent *e);
signals:
    void cubeClicked(int x,int y);

public slots:

private:
    QLabel *label;
    int x,y;
};

#endif // CUBE_H
