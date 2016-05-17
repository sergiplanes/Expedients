// Llibreria entrada/sortida: Totes les funcions d’entrada i sortida de dades (de/a fitxer i entrada manual de dades).

#include "practica_2.h"

void carregar_Fitxer();
void carregar_Expedients();
void carregar_Asignatures();
void procesar_fitxers();
void nou_alumne();
void alta_expedient();

void error(const char *s)
   {
     /* perror() devuelve la cadena S y el error (en cadena de caracteres) que tenga errno */
     perror (s);
     exit(EXIT_FAILURE);
}

void procesar_fitxer(char *archivo, sExpedients *e, sAsigatures *a){
     /*La funcio procesar fitxers, és aquella que ens permet guardar els valors dels diferents camps en el vector de estructures e*/
     FILE *expedients;
     FILE *asignatures;
     long ftam;
     int i,j;         //contador

     expedients=fopen(archivo, "r");
     asignatures=fopen(archivo, "r");
     if (expedients == NULL && asignatures == NULL)
       {
         /* Si ha pasado algo, sólo decimos el nombre */
         printf ("El contigunt del fitxer es errorni...\n");
         return;
         
       }
     else{
         /*fseek(expedients, 0L, SEEK_END);
         ftam=ftell(expedients);
         fclose(expedients);*/
         /* Si todo va bien, decimos el tamaño */
         printf ("%30s (%ld bytes)\n", archivo, ftam);
        /* for(i=0;i<sEMAX;i++){
             while(!feof(expedients)){
                 fscanf(expedients,"%s,%s,%s,%d,%d,%d,%s,%d,%f,%d \m", e[i].nom,e[i].primerCognom,e[i].segonCognom,e[i].NIA,e[i].curs,e[i].codiAsig,e[i].nomAsig,e[i].conv,e[i].nota,e[i].credits);
                 
             }
         }
         for(j=0;j<aMAX;j++){
            while(!feof(asignatures)){
                fscanf(asignatures,"%d,%d,%c,%d,%d,%d,%d,%c \m",a[j].num,a[j].grau,a[j].tipus,a[j].curs,a[j].trim,a[j].codiAsig,a[j].credits,a[j].nomAsig);
            }
         }*/
         fclose(expedients);
         fclose(asignatures);
         return;
     }
       
}

void carregar_Fitxer(sExpedients *e, sAsigatures *a){
        /* Creem un punter que conte el directori on son els nostres fitxers(exp's/asig) */
     DIR *directori_fitxers;
     /* en aquesta direccio de memoria guardarem la informacio del arxiu que es va carregant a cada moment*/
     struct dirent *ent;

     /* Obrim el directori*/
     directori_fitxers = opendir ("\dades");

     /*Comprovem que no hi hagi cap error*/
     if (directori_fitxers == NULL){ 
         printf("Sembla que no shha pogut carregar ningun fitxer comprova el directori...\n");
         return;
     }
     
     /* Començem llegint un a un tots els fitxers*/
     while ((ent = readdir (directori_fitxers)) != NULL) 
       {
         printf("Nom del fitxer detectat: %s\n",ent->d_name);
         /* Busca si hi ha un fitxer que contingui el nom seguent asgs-get.txt */
         if ( (strcmp(ent->d_name, "asgs-get")!=0) )
           {
             if(DEBBUG)
                 printf("L'ha detectat!\n");
             
             procesar_fitxer(ent->d_name,e,a);
           }
         else if( (strcmp(ent->d_name, "expedient_")!=0) )
             /*Igual pero amb el fitxer expedients*/
          {
             if(DEBBUG)
                 printf("L'ha detectat!\n");
            /* Una vez tenemos el archivo, lo pasamos a una función para procesarlo. */
             procesar_fitxer(ent->d_name,e,a); 
          }
       }
     closedir (directori_fitxers);

     return /*EXIT_SUCCESS*/;
   } 

void nou_alumne(sExpedients *e){ 
    char salto[] ="\n";
    char dades_personals[] ="**Dades Personals**";
    char nom[] ="Nom                             :";
    char nia[] ="NIA                                      :";
    char primer_cognom[] ="Primer cognom                   :";
    char segon_cognom[] ="Segoncognom                     :";
    
    printf("*********************\n");
    printf("A continuació se li demanaran les dades generals del alumne\n");
    printf("Nom\n");
    scanf("%s",&e[sEMAX+1].nom[N]);
    
    printf("1r cognom\n");
    scanf("%s",&e[sEMAX+1].primerCognom[N]);
    printf("2n cognom\n");
    scanf("%s",&e[sEMAX+1].segonCognom[N]);
    printf("NIA\n");
    scanf("%d",&e[sEMAX+1].NIA);
    
    FILE* expedients;
    expedients = fopen("expedient_.txt", "w");
    /*Dades personals*/
    fputs(dades_personals,expedients);
    fputs(salto,expedients);
    /*Nom*/
    fputs(nom,expedients);
    fputs(e[sEMAX+1].nom, expedients);
    fputs(salto,expedients);
    /*1r cognom*/
    fputs(primer_cognom,expedients);
    fputs(e[sEMAX+1].primerCognom, expedients);
    fputs(salto,expedients);
    /*2n cognom*/
    fputs(segon_cognom,expedients);
    fputs(e[sEMAX+1].segonCognom, expedients);
    fputs(salto,expedients);
    /*NIA*/
    fputs(segon_cognom,expedients);
    //fputs(e[sEMAX+1].NIA, expedients);
    
    fclose(expedients);
    printf("Proceso completado\n");
    
    
}

void alta_expedient(int nia_eval, sExpedients *e){
    int nia_error=0;
    
    printf("A continuació podra donar d'alta un nou expedient\n");
    printf("Per tal de que tot funcioni correctament, nececitem un NIA valid\n(Recordar que per que sigui valid te que tenir 5 digits \ni no pot ser cap NIA duplicat ja que no podem donar d'alta 2 persones amb el mateix NIA,): \n");
    scanf("%d",&nia_eval);
    
    do{
        for(int i=0;i<sEMAX;i++){
           if(nia_eval==e[i].NIA){
               printf("ERROR\n");
               printf("El NIA introduit ja forma part del programa, siusplau, cambii de nia o torni al menu principal.\n");
               printf("*********************\n");
               printf("Premi 1:[Cambiar NIA]\n");
               printf("Premi 2:[Per tornar al menu]\n");
               scanf("%d",&nia_error);
               switch(nia_error){
                   case 1:
                       /*Cambiar nia*/
                       printf("Torni a introduir el NIA: ");
                       scanf("%d",&nia_eval);
                       for(int i=0;i<sEMAX;i++){
                            if(nia_eval==e[i].NIA){
                               printf("Torni a introduir el NIA: ");
                               scanf("%d",&nia_eval); 
                            }else{
                               nou_alumne(e);
                            }
                       }
                       break;
                   case 2:
                       /*Tornar a menu principal*/                    
                       return;
                       break;
                   default:printf("Opcio incorrecte*");
                       /*opcio incorrecte*/     

               }
           }
       };   
    }while(nia_error!=0);
    
    nou_alumne(e);
    
}
