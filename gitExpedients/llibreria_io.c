// Llibreria entrada/sortida: Totes les funcions d’entrada i sortida de dades (de/a fitxer i entrada manual de dades).

#include "practica_2.h"

void carregar_Fitxer();
void carregar_Expedients();
void carregar_Asignatures();
void procesar_fitxers();

void error(const char *s)
   {
     /* perror() devuelve la cadena S y el error (en cadena de caracteres) que tenga errno */
     perror (s);
     exit(EXIT_FAILURE);
}

void procesar_fitxer(char *archivo, sExpedients *e, sAsigatures *a)
   {
     /* Para "procesar", o al menos, hacer algo con el archivo, vamos a decir su tamaño en bytes */
     /* para ello haremos lo que vemos aquí: http://totaki.com/poesiabinaria/2010/04/tamano-de-un-fichero-en-c/ */
     FILE *expedients;
     FILE *asignatures;
     long ftam;
     int i,j;         //contador

     expedients=fopen(archivo, "r");
     asignatures=fopen(archivo, "r");
     if (expedients == NULL)
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
         for(i=0;i<sEMAX;i++){
             while(!feof(expedients)){
                 fscanf(expedients,"%c,%c,%c,%d,%d,%d,%c,%d,%f,%d \m", e[i].nom,e[i].primerCognom,e[i].segonCognom,e[i].NIA,e[i].curs,e[i].codiAsig,e[i].nomAsig,e[i].conv,e[i].nota,e[i].credits);
             }
         }
         for(j=0;j<aMAX;j++){
            while(!feof(asignatures)){
                fscanf(asignatures,"\m",a[j].num,a[j].grau,a[j].tipus,a[j].curs,a[j].trim,a[j].codiAsig,a[j].credits,a[j].nomAsig);
            }
         }
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
         if ( (strcmp(ent->d_name, "asgs-get.txt")!=0) )
           {
             if(DEBBUG)
                 printf("L'ha detectat!\n");
             
             procesar_fitxer(ent->d_name,e,a);
           }
         else if( (strcmp(ent->d_name, "expedient_")!=0) )
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

