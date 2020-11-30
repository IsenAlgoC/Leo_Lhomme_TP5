#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;




TABLEAU newArray()
{
	TABLEAU tab;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));//allocation de la memoire
	if (tab.elt == NULL)/*si l'allocation à échouer*/
	{
		return tab;
	}
	for (int i = 0; i < TAILLEINITIALE; i++)
	{
		*((tab.elt) + i) = 0;// on initialise le tableau avec des 0
	}
	tab.eltsCount = 0;//eltsCount initialisé à 0
	tab.size = TAILLEINITIALE;
	return tab;
}

int incrementArraySize(TABLEAU* tab, int  incrementV)
{
	int* tmp;
	tmp = (int*)realloc((*tab).elt, ((*tab).size + incrementV) * sizeof(int));
	if (tmp == 0)
	{
		return -1;// renvoie -1 si erreur 
	}
	(*tab).elt = tmp;
	(*tab).size += incrementV;//nouvelle taille
	return (*tab).size;//reourne la nouvelle taille

}


int setElement(TABLEAU* tab, int posi, int element)//Ecrit un élément à une position donnée sans insertion
{
	if (posi <= 0)// si la position en negative retourne une erreure
		return 0;
	if ((tab->size) <= posi)
	{
		incrementArraySize(tab, posi - tab->size);//on augmente la taille du tableau 
		for (int i = tab->size; i < posi - tab->size; i++)
		{
			*((tab->elt) + i) = 0;
		}
		*((tab->elt) + posi - 1) = element;//écriture de l'element à pos-1 du tableau
		return ((tab->elt) + posi - 1);

	}
	*((tab->elt) + posi - 1) = element;
	return ((tab->elt) + posi - 1);
}


int displayElements(TABLEAU* tab, int startPos, int endPos)//Affiche le tableau de l’indice début à l’indice fin
{
	if ((tab->elt) == NULL || startPos >= (tab->size) || endPos >= (tab->size) || startPos < 0 || endPos >= (tab->size) < 0)//conditions d'erreur
	{
		return -1;
	}
	if (startPos >= endPos)//si la fin est supétieur au début n inverse
	{
		int tmp = startPos;
		startPos = endPos;
		endPos = tmp;

	}
	for (int i = startPos; i <= endPos; i++)
	{
		printf("|%d|", *((tab->elt) + i));

	}
	printf("\n");
	return 0;
}



int deleteElements(TABLEAU* tab, int startPos, int endPos)
{
	int j = 0;
	int* ntab = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int));//allocation de la memoire restreinte 
	if (ntab == NULL)
	{
		return(-1);
	}
	for (int i = 0; i <= tab->size - 1; i++) {
		if ((i < startPos) || (i > endPos)) {
			*(ntab + j) = *(tab->elt + i);
			j++;
		}
	}
	tab->size -= (endPos - startPos) + 1;
	tab->eltsCount -= (endPos - startPos) + 1;
	tab->elt = ntab;
	return(tab->size);




}
