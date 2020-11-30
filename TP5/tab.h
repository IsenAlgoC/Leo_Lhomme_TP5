#pragma once

#include <stdlib.h>
#include <stdio.h>

#define TAILLEDEPART 100
#define TAILLEPLUS 50

int initTab(int* tab, int size)
{
	if (size < 0)//test pour savoir si on a une liste qui existe
	{
		return(-1);
	}
	if (tab == NULL) //test pour savoir si notre pointeur n'est pas nul
	{
		return(-1);
	}
	for (int i = 0; i < size; i++)
	{
			tab[i] = 0; // donne la valeur 0 a la i eme valeur
	}
	return(size);
}

int remplirTab(int* tab)
{

	if (tab == NULL) //test pour savoir si notre pointeur n'est pas nul
	{
		return(-1);
	}
	for (int i = 0; i < 20; i++)
	{
		tab[i] = i+1; 
	}
	return(0);
}

int afficheTab(int* tab, int size, int nbElts)
{
	if (size < nbElts)
	{
		return(-1);
	}
	if (tab == NULL)
	{
		return(-1);
	}
	for (int i= 0; i < nbElts; i++)
	{
			printf("%d\n", tab[i]);
	}
	return(0);
}

int AjoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	int i = 0;
	if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		if (*nbElts >= *size) {
			int* test_tab = tab;
			tab = (int*)realloc(tab, (*size + TAILLEPLUS) * sizeof(int));
			if (test_tab == NULL) {
				tab = test_tab;
				return -1;
			}
			for (int i = 0; i < TAILLEPLUS; i++) {
				*(tab + *size + i) = 0;
			}
			*size += TAILLEPLUS;
		}
		*(tab + *nbElts) = element;
		*nbElts += 1;
		return *nbElts;
	}
}
