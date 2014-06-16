
#include "main.h"
#include <cppconn/prepared_statement.h>
using namespace sql;
Bdd::Bdd()
{
    try {
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "supinfo");
        con -> setSchema("SearchEngine");
    } catch (SQLException &e) {
		std::cout << "ERROR: SQLException in " << __FILE__;
		std::cout << " (" << __func__<< ") on line " << __LINE__ << std::endl;
		std::cout << "ERROR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << ")" << std::endl;

		if (e.getErrorCode() == 1047) {
			/*
			Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
			*/
			std::cout << "\nYour server does not seem to support Prepared Statements at all. ";
			std::cout << "Perhaps MYSQL < 4.1?" << std::endl;
		}
    }

}

bool Bdd::AjoutBdd(std::list<MotClef> &kList,char * u, std::list<MotClef>::iterator &itKey, unsigned int * id)
{   std::string name(u);

    //ajout de l'url

    stmt= con->prepareStatement("INSERT INTO Url  VALUES ('',?,?) ");
    stmt->setString(1,name);
    stmt->setInt(2,*id);

    stmt->execute();
     //ajout des mots cles

//std::cout << "Test" << std::endl;
    stmt= con->prepareStatement("INSERT INTO Keyword VALUES ('',?,?) ");

    for (itKey = kList.begin() ; itKey!=kList.end();itKey++)
    {
       // std::cout << *id << std::endl;


        //std::cout << (*itKey).getMot() << std::endl;
        name = (*itKey).getMot();
        stmt->setString(1,name);
        stmt->setInt(2,*id);
        stmt->execute();
    }
    delete stmt;
    std::string str;

    str="SELECT * FROM Keyword where id=" + boost::lexical_cast<std::string>(*id);

    stmt= con->prepareStatement("SELECT * FROM Keyword WHERE idu=(?)");
    stmt->setInt(1,*id);
    stmt->execute();


    return 0 ;

}
Bdd::~Bdd()
{
    delete stmt;
    delete con;

}
ResultSet * Bdd::SearchBdd(char * keyword)
{
     try {

    stmt= con->prepareStatement("SELECT url FROM Url U JOIN Keyword K ON K.keyword = (?)");
    stmt->setString(1,keyword);
    stmt->execute();
     } catch (SQLException &e) {
     std::cout <<
		std::cout << "ERROR: SQLException in " << __FILE__;
		std::cout << " (" << __func__<< ") on line " << __LINE__ << std::endl;
		std::cout << "ERROR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << ")" << std::endl;

		if (e.getErrorCode() == 1047) {
			/*
			Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
			*/
			std::cout << "\nYour server does not seem to support Prepared Statements at all. ";
			std::cout << "Perhaps MYSQL < 4.1?" << std::endl;
		}
    }
    return stmt -> getResultSet();
}
