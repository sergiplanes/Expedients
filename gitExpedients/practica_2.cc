//Programa principal: Almenys la funció main i les funcions addicionals que calgui o tingui sentit.


#include <stdio.h>
#include "practica_2.h"

void carregar_Fitxer();
void carregar_Expedients();
void carregar_Asignatures();


/*int carregar_fitxers(FILE * expedients,FILE * asignatures){
    
        expedients=fopen("dades\expedient_12345.txt","r");   //Obrim el fitxer "estudiants.txt" dins el punter de tipos fitxer f.
        asignatures=fopen("dades\asgs-get.txt","r");   //Obrim el fitxer "estudiants.txt" dins el punter de tipos fitxer f.
    
        if(expedients && asignatures==NULL){                    //Aquesa clausula if, es per comprovar si el fitxer "estudiants.txt"
            printf("ERROR \n");         //te algun coningut o si el programa el carrega correctament.
            printf("Revisa el fitxer estudiants.txt");

            return (0);
        }
}*/
void nou_alumne(sExpedients *e){
    printf("*********************\n");
    printf("A continuació se li demanaran les dades generals del alumne\n");
    printf("Nom\n");
    scanf("%c",&e[1].nom);
    printf("1r cognom\n");
    scanf("%c",&e[1].primerCognom);
    printf("2n cognom\n");
    scanf("%c",&e[1].segonCognom);
    printf("NIA\n");
    scanf("%d",&e[1].NIA);
}

void alta_expedient(int nia_eval, sExpedients *e){
    printf("A continuació podra donar d'alta un nou expedient\n");
    printf("Per tal de que tot funcioni correctament, nececitem un NIA valid\n(Recordar que per que sigui valid te que tenir 5 digits \ni no pot ser cap NIA duplicat ja que no podem donar d'alta 2 persones amb el mateix NIA,): \n");
    scanf("%d",&nia_eval);

    for(int i=0;i<sEMAX;i++){
        if(nia_eval==e[i].NIA){
            int nia_error=0;
            printf("ERROR\n");
            printf("El NIA introduit ja forma part del programa, siusplau, cambii de nia o torni al menu principal.\n");
            printf("*********************\n");
            printf("Premi 1:[Cambiar NIA]\n");
            printf("Premi 2:[Per tornar al menu]\n");
            scanf("%d",&nia_error);
            switch(nia_error){
                case 1:
                    /*Cambiar nia*/
                    
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
    nou_alumne(e);
    
}

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
                //carregar_Fitxer(e,a);
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
