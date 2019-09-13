#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include <QList>

class Util
{
public:
    Util();
    static int random(int min, int max);
    static std::string  tolower( std::string str );
};

#endif // UTIL_H
