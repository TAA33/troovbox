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
    Url(const char nm[501]);
    char * getname();
    void setname(char nm[501]);
    void incScore();
    int getScore();
};

#endif // URL_H_INCLUDED
