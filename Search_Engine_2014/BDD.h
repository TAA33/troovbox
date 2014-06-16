#ifndef BDD_H_INCLUDED
#define BDD_H_INCLUDED

class Bdd
{
    private:
        sql::Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *stmt;


    public:
    Bdd();
    ~Bdd();
    sql::ResultSet * SearchBdd(char * keyword);
    bool AjoutBdd(std::list<MotClef> &kList,char * u, std::list<MotClef>::iterator &itKey,unsigned int * id);

};

#endif // BDD_H_INCLUDED
