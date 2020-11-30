#include<stdio.h>
#include<stdlib.h>
#include"tab.h"
#define TAB2SIZE 100
#define _SIZE_ 20

int main()
{
	int mytab1[10];

	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 0;
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) 
	{ 
		initTab(myTab2, tabSize); 
	}
	else 
	{ 
		printf("mémoire insuffisante"); return(-1); 
	}
	
	initTab(myTab2, 20);
	remplirTab(myTab2);
	afficheTab(myTab2, 20, 12);

	free(myTab2);
}