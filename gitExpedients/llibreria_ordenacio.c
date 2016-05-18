// Llibreria d’ordenació: Les funcions relacionades (d’alguna manera) en la cerca i ordenació de les dades.
//Sergi Planes



#include "practica_2.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ordenar_vector();
int intercambiar();
void ordenar();


int intercambiar(int v[],int i,int j,int posmin){
    
    int aux;
    aux = v[i];
    v[i]=v[j];
    v[j]=aux; 
    return(v[i]);
    
    
}

void ordenar(int *v){
  
    int i,j,posmin;
    
              //N-1 o N-2
    for(i=0;i<N-1;i++){
        
        posmin=i;
        
        for(j=i;j<N-1;j++){
            
            if(v[j]<v[posmin]){
                
                posmin=j;
                intercambiar(v,i,j,posmin);
                
            }   
            
        }
        printf("%d",v[i]);
    }
   
    
}

int ordenar_vector(sExpedients *e, sAsigatures *a) {
    int exp_asig=0;

    do{
        printf("Esculli un contenidor de dades per ordenar: ");
        printf("1:Expedients");
        printf("2:Asignatures");
        printf("3:Sortir");
        scanf("%d",&exp_asig);
        switch(exp_asig){
            case 1:
                
                    //N-1 o N-2
                ordenar(e);
                break;
                
            case 2:

                    //N-1 o N-2
                ordenar(a);
                break;
            case 3:
                break;
            default:printf("Opcio incorrecta");
                
        }



    }while(exp_asig=!3);

}






