#include "Util.h"
#include "stdlib.h"
Util::Util()
{

}

int Util::random(int min, int max)
{
    srand((unsigned int)(time(NULL)));
    return (rand()%(max-min + 1) + min);
}
