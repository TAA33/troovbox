#ifndef CODE_SOURCE_H_INCLUDED
#define CODE_SOURCE_H_INCLUDED

#include "main.h"


class Code_Sources
{

private:
    char* spathTmp;
    FILE* fpListe;
    int err;



public:
    Code_Sources(std::string url ,std::list<Url> &listUrl,std::list<Url>::iterator &itUrl,unsigned int * itIndexeur);
    ~Code_Sources();
    std::list<Url>::size_type exec_parsing(std::list<Url> &listUrl,std::list<Url>::iterator &itUrl, unsigned int * i);
     MotClef * motclef;
     int getErr();

};

#endif // CODE_SOURCE_H_INCLUDED
