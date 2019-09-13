#include "Player.h"

#include <iostream>
#include <QLabel>

bool Player::checkInBoard(std::string s)
{
  std::cout << "checkInBoard" << std::endl;
  return true;
}
bool Player::checkInLexicon(std::string word)
{
  std::cout << "checkInLexicon" << std::endl;
  bool res = lex->contains(word);
  if (res)
      lex->remove(word);
  return res;
}
