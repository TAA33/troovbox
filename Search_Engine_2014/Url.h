#ifndef URL_H_INCLUDED
#define URL_H_INCLUDED
#include "main.h"

class Url
{
    private:
    int score;
    char  name[501];
    public:
    Url();
    char * getname();
};

#endif // URL_H_INCLUDED
