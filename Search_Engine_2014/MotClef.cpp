#include "main.h"

MotClef::MotClef()
{

}
MotClef::MotClef(char * keyword)
{
    if ( strlen(keyword) > 3 )
    {
        Mot = (char *)malloc(10000 * sizeof(char));
        Mot = keyword ;
    }

}
char  *  MotClef::getMot()
{
    //std::cout << "Ajout: "<< Mot << std::endl;
    return Mot;

}
void MotClef::setMot(char * keyword)
{

    Mot = (char *)malloc(strlen(keyword) * sizeof(char));
    strcpy(Mot,keyword);

}
