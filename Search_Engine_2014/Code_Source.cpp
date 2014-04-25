#include "main.h"

Code_Sources::Code_Sources(std::string url)
{
    CURL *curl;
    spathTmp = (char *)malloc(50 * sizeof(char));
    const char* s1 = url.c_str();
    strcat(spathTmp,"/tmp/") ;
    strcat(spathTmp,s1) ;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, s1);

             FILE *fp = fopen(spathTmp, "w");
            curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);
            curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,fwrite);
            if (curl_easy_perform(curl) != CURLE_OK)
            {
                std::cout << "erreur de reception" ;

            }
            else
            {
                 fclose(fp);
                 exec_parsing();


            }



        }


//    system("pause");
    //return 0;

}
void Code_Sources::exec_parsing()
{
    std::cout << "Lancement de l'algoritme de parsing " ;
    char *args[]= {"parsing.sript",spathTmp,(char *) 0};
    execv("parsing.script",args);
    /*Creation de la liste d'url
    typedef std::list<Url*> uList;
    typedef std::list<Url*>::iterator uListIterator;
    uList listUrl;
    uListIterator itUrl;
    strcat(spathTmp,".liste");


    for( itUrl=listUrl.begin(); itUrl!=listUrl.end(); itUrl++ )
    {
        Url* pCurrentEnnemie = (*itor);
        if( pCurrentEnnemie->Visible()==true ){ ... }

    }
    */
    fpListe = fopen(spathTmp, "r");





    fclose(fpListe);
    //initalisation de la var liste

}
Code_Sources::~Code_Sources()
{

    curl_global_cleanup();

}
