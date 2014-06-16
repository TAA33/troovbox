#include "main.h"

using namespace std;

int main()
{
   //1//Initialisation __
        //definition des types de listes
        typedef std::list<Url> uList;
        typedef std::list<Url>::iterator uListIterator;
        typedef std::list<MotClef> kList;
        typedef std::list<MotClef>::iterator kListIterator;

        //list
        uList listUrl;
        uListIterator itUrl;
        kList listKey;
        kListIterator itKey;
//_______________________
//A//   Ajout d'une Url
//_______________________
    // j'initialise mes liste .
    // Pour chaque url dans la lsite
                //je check la base de donnée si url existe continue
                //je parse le code sourse
                    // je crre une liste de mot clef et je complete la liste d'url
                //j'ajoute  l'url et la liste de motclef associé A la bdd
                //




    switch(2)
    {

        case 1:
        {
            //var locale a l'action
            string url ("www.supinfo.com");
            unsigned int  itIndexeur =  0 ;


            //création premier code source
            Code_Sources *Code1 = new Code_Sources(url,listUrl,itUrl,&itIndexeur);
            itIndexeur++ ;
            //_____________

            //A.2// Ajout en Base Pour chaque élément de la liste
            for (itUrl = listUrl.begin() ; itUrl!=listUrl.end();itUrl++)
            {


                std::cout <<  "Numero d'index' :  " << itIndexeur << std::endl;
                Bdd * Base = new Bdd();

               //    for (itKey = listKey.begin() ; itKey!=listKey.end();itKey++)
              // {

               if (Code1->getErr()==0)
               {
                    Recherche * Recherche1 = new Recherche(Code1->motclef->getMot(),itKey,listKey);



                    //itindexeur doigt etre remplcé par dernier id de la bdd
                    Base->AjoutBdd(listKey,(*itUrl).getname(),itKey,&itIndexeur);
                    delete Base;
                    //suppréssion des eléments du parsing

                    // A.1// Vidage de la liste de mot clef
                    while (!listKey.empty())
                    {

                         itKey=listKey.end();
                         itKey--;
                         std::cout << "Réinitialisation de la liste de mots clefs: " << (*itKey).getMot() << std::endl;
                         listKey.pop_back();

                    }

                }
            //_____________________________________
            //A.3//Préparation a l'analyse du nouveau code source
                //Su^réssion du Code source
                delete Code1;
                //incrémentation des indexs
                itUrl++;
                itIndexeur++;
                //Création du prochain code source
                Code_Sources *Code1 = new Code_Sources((*itUrl).getname(),listUrl,itUrl,&itIndexeur);

            }
            break;
        }
        case 2:
//_______________________
//B// L'utilisateur effectue une recherche
//_______________________
    // Récupération de la recherche depuis un parametre de la fonction
                // Traitement du parametre
    //Pour chaque occurence des mot de la liste
        //je récupère une liste d'url via requete vers la base
        //Pour chaque url retrouvée
            //si les 7 premiere lettre commence pas http:// ou www
                //si l'url n'esite pas
                    //J'ajoute une entree dans ma liste d'url score = 1;
                //sinon
                //j'incrémente le score
    //je lance un script awk qui me génere la page

    //var locale a l'action
        sql::ResultSet *res;
        char * motclef;
        motclef = (char *)malloc(255 * sizeof(char));
         std::string http("http://");
         std::string www("www");
         bool b;
        strcpy(motclef,"cours Test looooll informatique");
     //B.1//écupération de la recherche depuis un parametre de la fonction
        //B.1.1// Traitement du parametre
        Recherche * Recherche2 = new Recherche(motclef,itKey,listKey);
     //B.2//Pour chaque occurence des mot de la liste
        for (itKey = listKey.begin() ; itKey!=listKey.end();itKey++)
        {
            //B.2.1//je récupère une liste d'url via requete vers la base
            Bdd * Base = new Bdd();

            res =  Base->SearchBdd((*itKey).getMot());

            while (res->next()) {
                b=true;
                string query = res->getString(1);


                    for (itUrl = listUrl.begin() ; itUrl!=listUrl.end();itUrl++)
                    {

                        if( strcmp( (*itUrl).getname(),query.c_str()) == 0)
                        {
                            // std::cout << (*itUrl).getname() << " is equal " << query.c_str() << std::endl;
                          b=false;
                          (*itUrl).incScore();
                          break;

                        }

                    }
                    if ( (query.compare(0,7,http,0,7) == 0 || query.compare(0,3,www) == 0) && b==true)
                    {
                         //std::cout << "Ajout de  :" << (*itUrl).getname() << std::endl;
                         listUrl.push_back(Url(query.c_str()));
                    }




              }
               std::cout << "La liste suivante vien d'etre créee  :" << std::endl;
               for (itUrl = listUrl.begin() ; itUrl!=listUrl.end();itUrl++)
                {
                    std::cout << "Ajout de  :" << (*itUrl).getname() << " with score " << (*itUrl).getScore()  << std::endl;

                }



        }



   }





    return 0;
}
