// Llibreria entrada/sortida: Totes les funcions d’entrada i sortida de dades (de/a fitxer i entrada manual de dades).

#include "practica_2.h"

void carregar_Fitxer();
void carregar_Expedients();
void carregar_Asignatures();

void error(const char *s)
   {
     /* perror() devuelve la cadena S y el error (en cadena de caracteres) que tenga errno */
     perror (s);
     exit(EXIT_FAILURE);
}

void procesoArchivo(char *archivo)
   {
     /* Para "procesar", o al menos, hacer algo con el archivo, vamos a decir su tamaño en bytes */
     /* para ello haremos lo que vemos aquí: http://totaki.com/poesiabinaria/2010/04/tamano-de-un-fichero-en-c/ */
     FILE *fich;
     long ftam;

     fich=fopen(archivo, "r");
     if (fich)
       {
         fseek(fich, 0L, SEEK_END);
         ftam=ftell(fich);
         fclose(fich);
         /* Si todo va bien, decimos el tamaño */
         printf ("%30s (%ld bytes)\n", archivo, ftam);
       }
     else
       /* Si ha pasado algo, sólo decimos el nombre */
       printf ("%30s (No info.)\n", archivo);
}

void carregar_Fitxer(){
        /* Creem un punter que conte el directori on son els nostres fitxers(exp's/asig) */
     DIR *directori_fitxers;
     /* en aquesta direccio de memoria guardarem la informacio del arxiu que es va carregant a cada moment*/
     struct dirent *ent;

     /* Obrim el directori*/
     directori_fitxers = opendir ("");

     /*Comprovem que no hi hagi cap error*/
     if (directori_fitxers == NULL){ 
         printf("Sembla que no shha pogut carregar ningun fitxer comprova el directori...");
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
                 printf("L'ha detectat!");
             
             procesoArchivo(ent->d_name);
           }
         else if( (strcmp(ent->d_name, "expedient_")!=0) )
          {
             if(DEBBUG)
                 printf("L'ha detectat!");
            /* Una vez tenemos el archivo, lo pasamos a una función para procesarlo. */
             procesoArchivo(ent->d_name); 
          }
       }
     closedir (directori_fitxers);

     return /*EXIT_SUCCESS*/;
   } 

