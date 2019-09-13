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
    bool checkInBoard(std::string s);
    std::vector<std::vector<char>> strCubes;
    void  CubeClear();
signals:
   void  possibleStr(std::string s);

public slots:
    void checkCube(int x,int y);
private:
    bool exist(std::vector<std::vector<char>>& board, std::string word);
    bool search(std::vector<std::vector<char>>& board, std::string word, int idx, int i, int j, std::vector<std::vector<bool>>& visited);

    bool ifConnected(std::vector<std::vector<int> > g);

    void  bfs(int x, int y, std::vector<std::vector<int> > &grid);

    int size;
    Cube **cubes;
    QString *letters;
    std::string word;
    std::vector< std::vector<int>> graph;
    inline int index(int i, int j) { return i * size + j; }
    static const QString STANDARD_CUBES[16];
    static const QString BIG_BOGGLE_CUBES[25];
};

#endif // BOARD_H
