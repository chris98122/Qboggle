#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "WordListWidget.h"
#include "Board.h"
#include <QLabel>

#include <QString>
#include <QWidget>
class Player: public WordListWidget
{

public:
    Player(QWidget *parent, QString label):WordListWidget (  parent, label)
    {
    };
    bool  checkInBoard(std::string s);
    bool  checkInLexicon(std::string s);

    bool  checkPrefix(std::string word);
public slots:
};

#endif // PLAYER_H
