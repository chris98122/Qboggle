#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include "WordListWidget.h"

#include <QLabel>

#include <QString>
#include <QWidget>
class  Computer: public WordListWidget
{
public:
    Computer(QWidget *parent, QString label):WordListWidget (parent, label)
    {
    };
    bool  checkInLexicon(std::string s);
    void setLex(Lexicon *lex)
    {
        this->lex=lex;
    }

};

#endif // COMPUTER_H
