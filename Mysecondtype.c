/**
*	Dominici Leonardo Matricola: 0000971128 Prova:
*	Libreria di supporto all'esame di Fondamenti di Informatica 1 del corso di Ingegneria Informatica UNIBO
*
*	Implementazione di Mysecondtype.h, include alcuni metodi che possono essere implementati o meno, Mysecondtype.h potrà essere usata sempliceente anche senza implementare nessuna delle funzioni in essa presenti.
*	Resteranno validi in quel caso i soli tyedef, per usare le funzioni di rdinamento degli array di Mysecondtype è necessario implementare compare e equals
*	Le altre funzioni non sono necessarie per il corretto funzionamento delle altre librerie incluse nella DocSolution
*
*	Fondamentale è implementare questo file correttamente in base al contenuto che si vuole inserire e in base
*	a come si decide di inizializzare Mysecondtype.h, altrimenti creerà una pioggia di errori a compilazione.
*
*	@author:	leodom01
*	@GitHub:	https://github.com/Leodom01
*	@version:	0.1
*
*	Visit my GitHub page to download the last version of the lib
*	For problems or infos please contact me at: leonardodominici01@gmail.com
*/

#pragma once
#include "Mysecondtype.h"
#include <stdlib.h>
#include <stdio.h>

//void printMySecondType(mySecondType target){}

//int equalsMySecondType(mySecondType a, mySecondType b){return int;}

//int comparemySecondType(mySecondType a, mySecondType b){return int;}

void printMySecondType(mySecondType target)
{
	printf("FieldA:  %d\n", target.fieldA);
}

int equalsMySecondType(mySecondType a, mySecondType b)
{
	if (a.fieldA == b.fieldA) {
		return 1;
	}
	else {
		return 0;
	}
}

int compareMySecondType(mySecondType a, mySecondType b)
{
	if (a.fieldA > b.fieldA) {
		return -1;
	}
	else if (equalsMySecondType(a, b)) {
		return 0;
	}
	else {
		return 1;
	}
}

void printArrMySecondType(mySecondType* arr, int dim)
{
	printf("Stampo array:\n");
	for (int i = 0; i < dim; i++) {
		printMySecondType(arr[i]);
	}
}

void scambiaMySecondType(mySecondType* a, mySecondType* b)
{
	mySecondType temp = *a;
	*a = *b;
	*b = temp;
}

int trovaPosMaxMySecondType(mySecondType v[], int n)
{
	int i, posMax = 0;
	for (i = 1; i < n; i++)
		if (compareMySecondType(v[posMax], v[i]) == 1) posMax = i;
	return posMax;
}

void insOrdMySecondType(mySecondType v[], int pos)
{
	int i = pos - 1;
	mySecondType x = v[pos];
	while (i >= 0 && compareMySecondType(x, v[i]) == 1) {
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}
	v[i + 1] = x;
}

void naiveSortMySecondType(mySecondType* arr, int size)
{
	int p;
	while (size > 1) {
		p = trovaPosMaxMySecondType(arr, size);
		if (p < size - 1) {
			scambiaMySecondType(&arr[p], &arr[size - 1]);
		}
		size--;
	}
}

void bubbleSortMySecondType(mySecondType* arr, int size)
{
	int i, ordinato = 0;
	while (size > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < size - 1; i++)
			if (compareMySecondType(arr[i], arr[i+1]) == -1) {
				scambiaMySecondType(&arr[i], &arr[i + 1]);
				ordinato = 0;
			}
		size--;
	}
}

void insertSortMySecondType(mySecondType* arr, int size)
{
	int k;
	for (k = 1; k < size; k++)
		insOrdMySecondType(arr, k);
}

void mergeMySecondType(mySecondType v[], int i1, int i2, int fine, mySecondType vout[])
{
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compareMySecondType(v[i], v[j]) == 1)
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) {
		vout[k] = v[i++]; k++;
	}
	while (j <= fine) {
		vout[k] = v[j++]; k++;
	}
	for (i = i1; i <= fine; i++) {
		v[i] = vout[i];
	}
}

void mergeSortInnerMySecondType(mySecondType v[], int first, int last, mySecondType vout[])
{
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSortInnerMySecondType(v, first, mid, vout);
		mergeSortInnerMySecondType(v, mid + 1, last, vout);
		mergeMySecondType(v, first, mid + 1, last, vout);
	}
}

void mergeSortMySecondType(mySecondType* in_arr, int size, mySecondType* out_arr)
{
	mergeSortInnerMySecondType(in_arr, 0, size - 1, out_arr);
}

void quickSortInnerMySecondType(mySecondType a[], int iniz, int fine)
{
	int i, j, iPivot;
	mySecondType pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do { /* trova la posizione del pivot */
			while (i < j && (compareMySecondType(a[i], pivot) == 1 || compareMySecondType(a[i], pivot) == 0)) i++;
			while (j > i && (compareMySecondType(a[j], pivot) == -1 || compareMySecondType(a[j], pivot) ==  0)) j--;
			if (i < j) scambiaMySecondType(&a[i], &a[j]);
		} while (i < j);
		if (i != iPivot && equalsMySecondType(a[i], a[iPivot]) == 0)
		{
			scambiaMySecondType(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortInnerMySecondType(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortInnerMySecondType(a, iPivot + 1, fine);
	}
}

void quickSortMySecondType(mySecondType* arr, int size)
{
	quickSortInnerMySecondType(arr, 0, size - 1);
}
