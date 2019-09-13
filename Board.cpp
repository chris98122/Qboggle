#include "Board.h"
#include "Cube.h"
#include "Util.h"
#include <QGridLayout>
#include "string.h"
#include <vector>
#include <iostream>
const QString Board::STANDARD_CUBES[16]  = {
        "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
        "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
        "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
        "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};

const QString Board::BIG_BOGGLE_CUBES[25]  = {
        "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
        "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
        "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
        "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
        "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

Board::Board(QWidget *parent, int size, const QString *cubeLetters) : QWidget(parent)
{
    this->size = size;
    this->cubes = new Cube*[size * size];
    this->letters = new QString[size * size];
    for (int i = 0; i < size * size; ++i)
        this->letters[i] = cubeLetters[i];

    QGridLayout *layout = new QGridLayout();
    layout->setMargin(20);
    layout->setSpacing(10);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            this->cubes[index(i, j)] = new Cube(this);
            layout->addWidget(this->cubes[index(i, j)], i, j, Qt::AlignmentFlag::AlignCenter);
        }
    }
    setLayout(layout);

    for (int i = 0; i < size; ++i) {
        std::vector<char> vec;
        vec.clear();
        for (int j = 0; j < size; ++j) {
            QString input = this->letters[index(i, j)].at(Util::random(0,size));
            this->cubes[index(i, j)]->setLetter(input);

            vec.push_back(tolower(input.toStdString().data()[0]));
        }
        strCubes.push_back( vec);
    }
    // this->setStyleSheet("background-color:grey; border: 3px solid");
}
bool Board::checkInBoard(std::string word)
{
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            std::cout <<strCubes[i][j]  ;
//        }
//          std::cout  << std::endl;
//    }
   std::cout <<    word;
  std::cout << "checkInBoard" << std::endl;
  bool res = exist(strCubes ,word);
  std::cout<<res<< std::endl;
  return res ;
}

bool Board::exist(std::vector<std::vector<char>>& board, std::string word) {
       if (board.empty() || board[0].empty()) return false;
       int m = board.size(), n = board[0].size();
       std::vector< std::vector<bool>> visited(m, std::vector<bool>(n));
       for (int i = 0; i < m; ++i) {
           for (int j = 0; j < n; ++j) {
               if (search(board, word, 0, i, j, visited)) return true;
           }
       }
       return false;
   }
bool Board::search(std::vector<std::vector<char>>& board, std::string word, int idx, int i, int j, std::vector<std::vector<bool>>& visited) {
       if (idx == word.size()) return true;
       int m = board.size(), n = board[0].size();
       if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
       visited[i][j] = true;
       bool res = search(board, word, idx + 1, i - 1, j, visited)
                || search(board, word, idx + 1, i + 1, j, visited)
                || search(board, word, idx + 1, i, j - 1, visited)
                || search(board, word, idx + 1, i, j + 1, visited)
               ||search(board, word, idx + 1, i+1, j + 1, visited)
               ||search(board, word, idx + 1, i-1, j - 1, visited)
               ||search(board, word, idx + 1, i+1, j - 1, visited)
               ||search(board, word, idx + 1, i-1, j + 1, visited);
       visited[i][j] = false;
       return res;
   }
Board::~Board()
{
    if (cubes) delete[] cubes;
    if (letters) delete[] letters;
}

void Board::shake()
{
    // Shake Cubes
}
