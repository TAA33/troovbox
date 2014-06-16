#include "main.h"

Url::Url()
{


}
Url::Url(const char * nm )
{
    score=0;
    strcpy(name,nm);

}
char * Url::getname()
{
    return name;
}
void Url::setname(char * nm)
{
//suppréssion du backslash n en fin d'url
    char subbuff[3];
    memcpy( subbuff, &nm[strlen(nm)-1], 2);
    subbuff[2] = '\0';
   // std::cout << subbuff  ;
        if (strcmp(subbuff,"\n") == 0)
        {
            strncpy(name,nm,strlen(nm)-1);
        }
// strcpy(name,nm);
//suppréssion des slash dans l'url

}
void Url::incScore()
{
    score++;
}
int Url::getScore()
{
    return  score;
}
