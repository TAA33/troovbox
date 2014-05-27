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
                    // make it recursive

            }



        }


//    system("pause");
    //return 0;

}
void Code_Sources::exec_parsing()
{
    std::cout << "Lancement de l'algoritme de parsing "<< std::endl ;
     int status;
     pid_t pID = fork();

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
            itUrl = listUrl.begin();
        while (!feof(fpListe)  )
        {

            if (fgets ( (*itUrl).getname() , 500 , fpListe) != NULL );

            listUrl.push_front (Url());
            itUrl++;
         }
        }
    }











    fclose(fpListe);
    //initalisation de la var liste
}
Code_Sources::~Code_Sources()
{

  //  curl_global_cleanup();

}
