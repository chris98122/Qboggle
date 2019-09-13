#ifndef WORDLISTWIDGET_H
#define WORDLISTWIDGET_H

#include "WordTable.h"

#include <QWidget>

class WordListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WordListWidget(QWidget *parent = nullptr, QString label = "");
    void addScore(int s);
    void addWord(QString word);
    void reset();
signals:

public slots:

private:
    QString label;
    QList<QString> words;
    int score;
    WordTable *wordTable;
};

#endif // WORDLISTWIDGET_H