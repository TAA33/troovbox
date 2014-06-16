#ifndef MOTCLEF_H_INCLUDED
#define MOTCLEF_H_INCLUDED

class MotClef
{
    private :
        char * Mot;

    public  :
        MotClef();
        MotClef(char * mot);
        char * getMot();
        void setMot(char * keyword);
};

#endif // MOTCLEF_H_INCLUDED
