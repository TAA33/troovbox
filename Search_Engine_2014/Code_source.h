#ifndef CODE_SOURCE_H_INCLUDED
#define CODE_SOURCE_H_INCLUDED

#include "main.h"

class Code_Sources
{

private:
    char* spathTmp;
    FILE* fpListe;


     // Déclarationde la list url

public:
    Code_Sources(std::string url);
    ~Code_Sources();
    void exec_parsing();

};

#endif // CODE_SOURCE_H_INCLUDED
