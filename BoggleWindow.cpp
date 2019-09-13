#include "BoggleWindow.h"
#include "lexicon.h"

#include "Util.h"
#include <QFile>
#include <QHBoxLayout>
#include <QTextEdit>
#include <iostream>
#include "string.h"
#include "Player.h"
#include "Computer.h"
#include <QDebug>
BoggleWindow::BoggleWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("QBoggle!");
    this->setFixedSize(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);

    me = new Player(this, "Me");
    computer = new Computer(this, "Computer");
    board = new Board(this);
    console = new Console(this);


    me->setGeometry(20, 20, 230, 300);
    board->setGeometry(230, 0, 300, 300);
    computer->setGeometry(800 - 50 - 200, 20, 230, 300);
    console->setGeometry(30, 320, 740, 260);



//    for (std::string s: lex) {
//        std::cout << s << std::endl;
//    }

    console->write("Welcome to the game Boggle!\n");

    connect(console,SIGNAL(newLineWritten(QString)),this,SLOT(checkwords(QString)));
}
void BoggleWindow::checkwords(QString s)
{

    std::string str = Util::tolower(s.toStdString().data());
    if(str =="")
    {
        disconnect(console,SIGNAL(newLineWritten(QString)),this,SLOT(checkwords(QString)));
        //computer mode ,lex copied
        computer->setLex( me->lex);
        console->clear();
        console->write("Computer Mode\n");
    }
    if(str.size() >= 4 && board->checkInBoard (str) && me->checkInLexicon( str))
    {
       //add to word table;
        me->addWord(s);
        me->addScore(str.size()-3);
        me->updateScore();
    }



}
BoggleWindow::~BoggleWindow()
{
}
