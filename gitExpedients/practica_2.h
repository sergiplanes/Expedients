/*
 * File:Practica_2.h
 * Autors:Sergi Planes and Adrian Ribera
 */

#ifndef _practica_2_H
#define	_practica_2_H




#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define sEMAX 25
#define aMAX 111
#define N 50
#define DEBBUG 1


typedef struct sExpedients{
    char nom[N];
    char primerCognom[N];
    char segonCognom[N];
    int NIA;
    int curs;
    int codiAsig;
    char nomAsig[N];
    int conv;
    float nota;
    int credits;
}sExpedients;

typedef struct sAsignatures{
    int num;
    char grau[N];
    char tipus[N];
    int curs;
    int trim;
    int codiAsig;
    int credits;
    char nomAsig[N];
}sAsigatures;



#endif	/* _practica_2_h */

