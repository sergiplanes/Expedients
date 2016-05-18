//Programa principal: Almenys la funció main i les funcions addicionals que calgui o tingui sentit.
//Sergi Planes

#include <stdio.h>
#include "practica_2.h"
#include "llibreria_io.c"

//void carregar_Fitxer();
void carregar_Expedients();
void carregar_Asignatures();


void entrar_matricula(){
    
}
void entrar_notes_manual(){
    
}
void estat_expedient(){
    
}

void menu(){
    int menu=0;               //Declarem la variable que el menu fara servir.
    sExpedients e[sEMAX];       //Declarem el vector del tipos expedients...
                /*MAX es una constant que ens deixa posar un maxim de 999 alumnes o expedients de alumne*/
    sAsignatures a[sEMAX];
    
    int nia_eval;             //Declarem una variable per comparar si el nia existeix...
    
    FILE * expedients;       //Declarem la variable que contindra el fitxer expedients.
    FILE * asignatures;       //Declarem la variable que contindra el fitxer expedients.
    
    do{
        printf("***********Menu inici UPF, expedients***********\n");
        printf("Les operacions mínimes que ha d’implementar el programa són:\n");
        printf("1. Carregar fitxers: carrega fitxers existents\n");
        printf("2. Alta d’expedient: Registra un alumne nou i crea un expedient amb les dades generals però sense assignatures\n");
        printf("3. Entrar matricula: crea expedients nous i modifica fitxers expedients existents\n");
        printf("4. Entrar notes manualment: entra totes les notes d’una assignatura (i actualitza fitxers)\n");
        printf("5. (opcional) Estat dels expedients: per cada expedient en memòria mostra el resum de l’expedient \n i indica en quina situació estroba dins el pla docent que està matriculat (veure secció 1.2)\n");
        printf("Seleccioni una de les opcions llistades:\n");

        scanf("%d",&menu);
        switch(menu) {
            case 1:
                /*1. Carregar fitxers: carrega fitxers existents*/
                carregar_Fitxer(e,a);
                break;

            case 2:
                /*2. Alta d’expedient: Registra un alumne nou i crea un expedient amb les dades generals però sense assignatures*/
                alta_expedient(nia_eval,e);
                break;

            case 3:
                /*3. Entrar matricula: crea expedients nous i modifica fitxers expedients existents*/
                entrar_matricula();
                break;

            case 4:
                /*4. Entrar notes manualment: entra totes les notes d’una assignatura (i actualitza fitxers)*/
                entrar_notes_manual();
                break;

            case 5:
                /*"5. (opcional) Estat dels expedients: per cada expedient en memòria mostra el resum de l’expedient \n i indica en quina situació estroba dins el pla docent que està matriculat (veure secció 1.2)*/
                estat_expedient();
                break;
                
            default:printf("Opcio incorrecte*");
        }
    }while(menu!=6);
    fclose(expedients);
    fclose(asignatures);
   
}

int main() {
    
    menu();
    
}
