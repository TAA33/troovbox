#ifndef RECHERCHE_H_INCLUDED
#define RECHERCHE_H_INCLUDED

class Recherche
{
    private:
        char  sSearch[255];


    public:
        Recherche(char * sr,std::list<MotClef>::iterator &itKey, std::list<MotClef> &listKey);
        std::list<MotClef>  getKey();
};

#endif // RECHERCHE_H_INCLUDED
