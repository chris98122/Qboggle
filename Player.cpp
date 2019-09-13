#include "Player.h"

#include <iostream>
#include <QLabel>

#include <iostream>
#include "string.h"
bool Player::checkInLexicon(std::string word)
{
  std::cout << "checkInLexicon" << std::endl;
  bool res = lex->contains(word);
  if (res)
      lex->remove(word);
  return res;
}

bool Player::checkPrefix(std::string word)
{
     return lex->containsPrefix(word);
}
