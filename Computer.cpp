#include "Computer.h"

#include <iostream>
#include <QLabel>


void Computer::findAll(std::vector<std::vector<char>>& board)
{

    int m = board.size(), n = board[0].size();
    std::vector< std::vector<bool>> visited(m, std::vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
           search(board,"",0,0,visited);
        }
    }

}
void Computer::search(std::vector<std::vector<char>>& board, std::string word, int i, int j, std::vector<std::vector<bool>>& visited)
{
    int m = board.size(), n = board[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] ) return;
    visited[i][j] = true;
    word = word + board[i][j];
    if(word.size()<4)
    {
        search(board, word,i - 1, j, visited);
        search(board, word,i + 1, j, visited);
        search(board, word,i, j - 1, visited);
        search(board, word,i, j + 1, visited);
        search(board, word,i+1, j + 1, visited);
        search(board, word,i-1, j - 1, visited);
        search(board, word,i+1, j - 1, visited);
        search(board, word,i-1, j + 1, visited);
    }
    else if(word.size()>=4 && lex->containsPrefix(word))
    {
        if(lex->contains(word))
        {
             addWord(QString(word.data()));
             lex->remove(word);
             //res.push_back(word);
             addScore(word.size()-3);
             updateScore();
        }
        search(board, word,i - 1, j, visited);
        search(board, word,i + 1, j, visited);
        search(board, word,i, j - 1, visited);
        search(board, word,i, j + 1, visited);
        search(board, word,i+1, j + 1, visited);
        search(board, word,i-1, j - 1, visited);
        search(board, word,i+1, j - 1, visited);
        search(board, word,i-1, j + 1, visited);
    }
    visited[i][j] = false;
}
