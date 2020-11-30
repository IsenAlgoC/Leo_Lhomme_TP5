#include<stdio.h>
#include<stdlib.h>
#include "Exo2.h"
#define TAILLEINITIALE 100;


int main()
{
	int ajoutoctet;
	int position;
	int element;
	int positiondepart, positionfin;
	int positiondepart2, positionfin2;

	TABLEAU tab = newArray();
	printf("nombre d'octet a ajouter :");
	scanf_s("%d", &ajoutoctet);
	incrementArraySize(&tab, ajoutoctet);
	printf("entrer la position et l'element a cette position\n");
	scanf_s("%d %d", &position, &element);
	setElement(&tab, position, element);
	printf("entrer l'intervalle d'affichage(position de depart /position de fin)\n");
	scanf_s("%d %d", &positiondepart, &positionfin);
	displayElements(&tab, positiondepart, positionfin);
	return (0);
}