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
    void setLex(Lexicon *lex)
    {
        this->lex=lex;
    }
    void findAll(std::vector<std::vector<char>>& board);
    void search(std::vector<std::vector<char>>& board,std::string word, int i, int j, std::vector<std::vector<bool>>& visited );
};

#endif // COMPUTER_H
