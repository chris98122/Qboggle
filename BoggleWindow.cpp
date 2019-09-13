#include "BoggleWindow.h"
#include "lexicon.h"

#include <QFile>
#include <QHBoxLayout>
#include <QTextEdit>
#include <iostream>
#include "string.h"
#include "Player.h"
#include <QDebug>
BoggleWindow::BoggleWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("QBoggle!");
    this->setFixedSize(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);

    me = new Player(this, "Me");
    computer = new WordListWidget(this, "Computer");
    board = new Board(this);
    console = new Console(this);


    me->setGeometry(20, 20, 230, 300);
    board->setGeometry(230, 0, 300, 300);
    computer->setGeometry(800 - 50 - 200, 20, 230, 300);
    console->setGeometry(30, 320, 740, 260);

    QFile qFile(":/res/EnglishWords.txt");
    if (!qFile.open(QIODevice::ReadOnly)) {
        throw new std::runtime_error("Resource file not found!");
    }
    Lexicon lex(qFile);

//    for (std::string s: lex) {
//        std::cout << s << std::endl;
//    }

    console->write("Welcome to the game Boggle!\n");
}
void BoggleWindow::checkwords(QString s)
{
        //std::cout <<
    std::string str = s.toStdString().data();
    me-> checkInBoard ( str);
    me->checkInLexicon( str);
    std::cout <<str;

}
BoggleWindow::~BoggleWindow()
{
}
