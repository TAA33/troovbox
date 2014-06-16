#include "main.h"

Recherche::Recherche(char * sr, std::list<MotClef>::iterator &itKey, std::list<MotClef> &listKey)
{
     char  key[1];
     char * ptok;
     ptok = (char *)malloc(10000 * sizeof(char));

     key[0]=' ';

    if (strlen(sr)< 10000 && strlen(sr)>3)
    {
        std::cout << ptok << std::endl;
        // découpage et création de la liste de keyword
        ptok = strtok(sr,key);
        itKey = listKey.begin();


        while (ptok != NULL)
        {

            listKey.push_front (MotClef(ptok));
            itKey++;
            //
            ptok = strtok(NULL,key);


        }

    }
    else
    {
        std::cout << "Erreur: Taille de Recherche" << sr << std::endl ;
    }
}

