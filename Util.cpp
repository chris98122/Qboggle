#include "Util.h"
#include "stdlib.h"

#include "string.h"
Util::Util()
{

}

int Util::random(int min, int max)
{
    srand((unsigned int)(time(NULL)));
    return (rand()%(max-min + 1) + min);
}
std::string Util::tolower( std::string str )
{
    for(unsigned i = 0; i < str.length(); i++)
        str[i] = std::tolower(str[i]);
    return str;
}
