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

int comparemySecondType(mySecondType a, mySecondType b)
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

int compareMySecondType(mySecondType a, mySecondType b)
{
	return 0;
}

void scambiaMySecondType(mySecondType* a, mySecondType* b)
{
}

int trovaPosMaxMySecondType(mySecondType v[], int n)
{
	return 0;
}

void insOrdMySecondType(mySecondType v[], int pos)
{
}

void naiveSortMySecondType(mySecondType* arr, int size)
{
}

void bubbleSortMySecondType(mySecondType* arr, int size)
{
}

void insertSortMySecondType(mySecondType* arr, int size)
{
}

void mergeMySecondType(mySecondType v[], int i1, int i2, int fine, mySecondType vout[])
{
}

void mergeSortInnerMySecondType(mySecondType v[], int first, int last, mySecondType vout[])
{
}

void mergeSortMySecondType(mySecondType* in_arr, int size, mySecondType* out_arr)
{
}

void quickSortInnerMySecondType(mySecondType a[], int iniz, int fine)
{
}

void quickSortMySecondType(mySecondType* arr, int size)
{
}
