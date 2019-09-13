#ifndef WORDLISTWIDGET_H
#define WORDLISTWIDGET_H

#include "WordTable.h"

#include "lexicon.h"
#include <QWidget>
#include <QLabel>

class WordListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WordListWidget(QWidget *parent = nullptr, QString label = "");
    void addScore(int s);
    void addWord(QString word);
    void reset();
    void updateScore();

    Lexicon  *lex ;
signals:

public slots:

protected:
    QString label;
    QLabel *scoreLabel ;
    QList<QString> words;
    int score;
    WordTable *wordTable;
};

#endif // WORDLISTWIDGET_H
