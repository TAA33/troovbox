#include "main.h"

//it indéxeur est la taille de la précédente liste
Code_Sources::Code_Sources(std::string url,std::list<Url> &listUrl,std::list<Url>::iterator &itUrl,unsigned int * itIndexeur)
{
    std::cout << "Telechargement de : "<< url<< std::endl ;
    CURL *curl;
    // it indexeurTerminal est la taille de la nouvelle liste
    unsigned int i=0;
    std::list<Url>::size_type itIndexeurTerminal;
    motclef = new MotClef();

    spathTmp = (char *)malloc(50 * sizeof(char));
     std::cout << spathTmp << std::endl;


    const char* s1 = url.c_str();
    char  curlError[CURL_ERROR_SIZE];


    sprintf (spathTmp,"/tmp/%u",*itIndexeur);

    //strcat(spathTmp,itUrl) ;



    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl)
        {
                curl_easy_setopt(curl, CURLOPT_URL, s1);
               // curl_easy_setopt(curl,CURLOPT_ERRORBUFFER,curlError);
                 FILE *fp = fopen(spathTmp, "w");
                 if (fp != NULL)
                {
                curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);
                curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,fwrite);

                if (curl_easy_perform(curl) != CURLE_OK)
                {
                     FILE *log = fopen("/var/log/Se_curl.log","wt");
                    fprintf (log, "%s ", curlError);
                    std::cout << "Erreur ouverture de fichier" << std::endl;
                    fclose(log);
                    err = 1;

                }
                else
                {
                    err=0;
                    curl_easy_cleanup(curl);
                     fclose(fp);
                     i=*itIndexeur;
                   exec_parsing(listUrl,itUrl,itIndexeur);

                     // make it recursive
                     //condition de sortie
                     //soit tout les éléments de la liste ont été analsyé.
                    /* itUrl=listUrl.begin();

                     do
                     {

                        itUrl++;
                         itUrl++;
                        i++;
                        //std::cout << "erreur de boucle" ;
                        if (i>itIndexeur && i<itIndexeurTerminal)
                        Code_Sources *Code = new  Code_Sources((*itUrl).getname(),listUrl,itUrl,itIndexeur);

                     }while (itUrl != listUrl.end());

                        */


                    }

                }
                else
                {
                  std::cout << "Erreur ouverture de fichier" ;

                }

        }


//    system("pause");
    //return 0;

}
std::list<Url>::size_type Code_Sources::exec_parsing(std::list<Url> &listUrl,std::list<Url>::iterator &itUrl,unsigned int * i)
{
    std::cout << "Lancement de l'algoritme de parsing "<< std::endl ;

     int status;
     char  cTmp[501];
      char  cTmpmot[8]="http://";
     char csubTmp[500];
     pid_t pID = fork();
     bool b;
   if (pID == 0)                // child

   {

        char *args[]= {"parsing.sript",spathTmp,(char *) 0};
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
       else
       {
        strcat(spathTmp,".liste");
        fpListe = fopen(spathTmp, "r");
        listUrl.push_front (Url());
        // on commence toujours a partir de la fin

            while (!feof(fpListe)  )
            {
                //on récupére la chaine
                if (fgets(cTmp , 500 , fpListe) != NULL )
                {
                     //cTmpsubstring pour suppréssion doublon a 1 caractere pres

                     /*memcpy( csubTmp,cTmp, strlen(cTmp)-2 );
                     csubTmp[501]='\0';*/
                     //std::cout << cTmp << std::endl ;
                    //on verifie que l'url n'existe pas déja
                    b = true;

                    ///
                    //important changer initialisation
                    ///
                    for (itUrl = listUrl.begin() ; itUrl!=listUrl.end();itUrl++)
                    {

                        if( strcmp( (*itUrl).getname(),cTmp) == 0 || strcmp( (*itUrl).getname(),csubTmp) == 0 )
                        {
                            b=false;
                            break;
                        }

                    }
                    if (b)
                    {
                         listUrl.push_back (Url());
                         itUrl--;
                         (*itUrl).setname(cTmp);

                    }
                    if (strncmp( (*itUrl).getname(),cTmpmot,7) != 0)
                    {
                            motclef->setMot((*itUrl).getname());
                            listUrl.pop_back ();
                            listUrl.pop_back ();
                            itUrl--;
                            itUrl--;
                    }
                }


             }




             itUrl = listUrl.begin();
             *i++;
             std::advance (itUrl,*i);

            // std::cout << motclef->getMot() << std::endl;
            return listUrl.size();
        }
    }


    fclose(fpListe);
    //initalisation de la var liste
}
Code_Sources::~Code_Sources()
{

  //  curl_global_cleanup();

}
int Code_Sources::getErr()
{
    return err;
}
