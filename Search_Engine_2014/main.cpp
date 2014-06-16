#include "main.h"

// Par Kassi Ehua...
using namespace std;
using namespace sql;
int main(int argc, char *argv[])
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




    switch((int)argv[1])
    {

        case 1:
        {
            //var locale a l'action
            string url (argv[0]);
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
        {
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
        strcpy(motclef,argv[0]);
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
              delete Base;




        }
         //std::cout << "La liste suivante vien d'etre créee  :" << std::endl;
           /* std::cout << "Content-type: text/html" << std::endl;
            std::cout << "<html>" << std::endl;
            std::cout << "   <body>" << std::endl;
            std::cout<< "<?php"<< std::endl;
            std::cout <<"session_start();" << std::endl;
            std::cout <<"if (!isset($_SESSION['login'])) {" << std::endl;
            std::cout << "   header ('Location: index.php');" << std::endl;
            std::cout <<  "  exit();"<< std::endl;
            std::cout <<"}"<< std::endl;
            std::cout <<"?>"<< std::endl;

            std::cout <<"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">"<< std::endl;
            std::cout <<"<html xmlns=\"http://www.w3.org/1999/xhtml\">"<< std::endl;
            std::cout <<"<head>"<< std::endl;
            std::cout <<"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />"<< std::endl;
            std::cout <<"<link rel=\"stylesheet\" href=\"mep.css\">"<< std::endl;
            std::cout <<"<head>"<< std::endl;
            std::cout <<"<title>Page de recherche</title>"<< std::endl;
            std::cout <<"</head>"<< std::endl;
            std::cout <<"<body>"<< std::endl;
            std::cout <<"Bienvenue <?php echo htmlentities(trim($_SESSION['login'])); ?> <br />
            std::cout <<"<div id="deconnexion"><a href="deconnexion.php">Déconnexion</a></div>
            std::cout <<"<div class="foot">Copyright 2014.<a href="mailto:165052@supinfo.com">Support WEB</a></div>
            std::cout <<"<div class="logo">
            std::cout <<" <img src="images/logo.jpg" alt="TROOVBOX"/>
            std::cout <<" <h3>Résultats de votre recherche.</h3>
            std::cout <<"</br>Il y a <?php echo $nb_resultats;// on affiche le nombre de résultats

            std::cout <<"if($nb_resultats > 1)
            std::cout <<"{ echo 'résultats'; } else { echo 'résultat'; } // on vérifie le nombre de résultats pour orthographier correctement.
            std::cout <<" ?>


            std::cout <<" <?php
            std::cout <<" while($donnees = mysql_fetch_array($query)) // on fait un while pour afficher la liste des fonctions trouvées, ainsi que l'id qui permettra de faire le lien vers la page de la fonction
            std::cout <<" {
            std::cout <<"    ?>
            std::cout <<"     <a href="membre.php?id=<? echo $donnees['id']; ?>"><? echo $donnees['nom_fonction']; ?></a><br/>
            std::cout <<" <?php
            std::cout <<"} // fin de la boucle
            std::cout <<" ?><br/>
            std::cout <<"<br/>
            std::cout <<"  <a href="membre.php">Faire une nouvelle recherche</a></p>





std::cout <<"</div>

std::cout <<"</body>
std::cout <<"</html>
*/          int cpt=0;
            int taille=(int)argv[2];
                for (itUrl = listUrl.begin() ; itUrl!=listUrl.end() && cpt<taille;itUrl++)
            {
                   cpt++;
                    std::cout << "<a href =\""<< (*itUrl).getname()<<"\">"<<(*itUrl).getname()<< "</a>"  << std::endl;

            }
            break;
        }
        case 3:
        {
    //_______________________
    //C// Le systeme effectue une mise a jour de la base
    //_______________________
        // Récupération des Urls depuisla Bdd
        //Pour chaque Url de la base
            //On parse l'url
            //Pour chaque url de la liste
                //si elles ne sontt pas présente dans la base de donnée
                //si l'url n'existe pas
                        //Je crée un nouveau processus fils qui lance la partie A;
                //sinon on passe a l'url suivante
            //
        sql::ResultSet *res;
        sql::Resultset *res2;
        Bdd * Base = new Bdd();
        Bdd * Base2 = new Bdd();
        int status;
        unsigned int itIndexeur;
        bool b;
        res1 =  Base->RecupBdd();
        res2 = Base2->RecupBdd();
        while (res1->next()) {
                b=true;
                string query = res->getString(1);
                Code_Sources *Code1 = new Code_Sources(query,listUrl,itUrl,&itIndexeur);
                for (itUrl = listUrl.begin() ; itUrl!=listUrl.end();itUrl++)
                {
                   while (res2->next())
                   {
                     query = res->getString(1);
                     if (query.compare((*itUrl).getname()) == 0)
                     {
                        break;
                     }
                     else
                     {
                        pid_t pID = fork();
                        bool b;
                       if (pID == 0)                // child

                       {

                            char *args[]= {"parsing.sript","PATHTOBIN",(char *) 0};
                            execv("parsing.script",args);
                            std::cout << "Child process ended normally" << std::endl;
                            exit(EXIT_SUCCESS);
                        }
                        else if (pID < 0)
                        {
                            std::cerr << "failed to fork" << std::endl ;
                        }
                        else
                        {
                           if ((pID = wait(&status)) == -1)
                           {
                                //Wait for child
                           }
                        }
                     }
                   }
                }
                break;

        }
        }
        default :
        std::cout << "Usage ./SearchEngine [1 Url |2 Motclef |3 ]  :" << (*itUrl).getname() << " with score " << (*itUrl).getScore()  << std::endl;





   }





    return 0;
}
