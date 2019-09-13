#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "WordListWidget.h"

#include <QLabel>

#include <QString>
#include <QWidget>
class Player: public WordListWidget
{
public:
    Player(QWidget *parent, QString label):WordListWidget (  parent, label){};
    bool  checkInBoard(std::string s);
    bool  checkInLexicon(std::string s);

};

#endif // PLAYER_H
