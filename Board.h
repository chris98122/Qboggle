#ifndef BOARD_H
#define BOARD_H

#include "Cube.h"

#include "string.h"
#include <vector>
#include <QWidget>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr, int size = 5, const QString *cubeLetters = BIG_BOGGLE_CUBES);
    virtual ~Board();
    void shake();
    bool checkInBoard(std::string s);
    std::vector<std::vector<char>> strCubes;

signals:

public slots:

private:
    bool exist(std::vector<std::vector<char>>& board, std::string word);
    bool search(std::vector<std::vector<char>>& board, std::string word, int idx, int i, int j, std::vector<std::vector<bool>>& visited);

    int size;
    Cube **cubes;
    QString *letters;
    inline int index(int i, int j) { return i * size + j; }
    static const QString STANDARD_CUBES[16];
    static const QString BIG_BOGGLE_CUBES[25];
};

#endif // BOARD_H
