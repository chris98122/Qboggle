#include "Computer.h"

#include <iostream>
#include <QLabel>


bool Computer::checkInLexicon(std::string word)
{
  std::cout << "checkInLexicon" << std::endl;
  bool res = lex->contains(word);
  if (res)
      lex->remove(word);
  return res;
}
