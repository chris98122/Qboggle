#ifndef BOGGLEWINDOW_H
#define BOGGLEWINDOW_H

#include "Board.h"
#include "Console.h"

#include "Player.h"

#include "Computer.h"
#include "WordListWidget.h"

#include <QMainWindow>

class BoggleWindow : public QMainWindow
{
    Q_OBJECT

public:
    BoggleWindow(QWidget *parent = 0);
    ~BoggleWindow();

public slots:
    void checkwords(QString words);
    void  checkPossibleStr(std::string s);
private:
    Player *me;
    Computer*computer;
    Board *board;
    Console *console;

    static const int BOGGLE_WINDOW_WIDTH = 800;
    static const int BOGGLE_WINDOW_HEIGHT = 600;
};

#endif // BOGGLEWINDOW_H
