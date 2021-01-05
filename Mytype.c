/**
*	Dominici Leonardo Matricola: 0000971128 Prova:
*	Libreria di supporto all'esame di Fondamenti di Informatica 1 del corso di Ingegneria Informatica UNIBO
*
*	Implementazione di Mytype.h, include alcuni metodi che possono essere implementati o meno, Mytype.h potrà essere usata sempliceente anche senza implementare nessuna delle funzioni in essa presenti.
*	Resteranno validi in quel caso i soli tyedef e la possibilità di usare list formate da elementi myType, per alcune funzioni della libreria Mylist.h è necessario implementare le funzioni equals e compare.
*	Per usare invece la funzione printList è necessario implementare printMytype.
*	Le altre funzioni non sono necessarie per il corretto funzionamento delle altre librerie incluse nella DocSolution
*
*	Fondamentale è implementare questo file coorettamente in base al contenuto che si vuole inserire e in base
*	a come si decide di inizializzare myType.h, altrimenti creerà una pioggia di errori a compilazione.
*
*	@author:	leodom01
*	@GitHub:	https://github.com/Leodom01
*	@version:	0.1
*
*	Visit my GitHub page to download the last version of the lib
*	For problems or infos please contact me at: leonardodominici01@gmail.com
*/

#pragma once
#include "Mytype.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//L'implementazione delle seguenti funzioni dipende fortemente da come è definito myType effettivamente e dallo scopo per cui deve essere usato
//Si suggerisce di implementare almeno compare e printMytype

void printMytype(myType target)
{
	printf("Field1:  %d\n", target.field1);
}

int compare(myType a, myType b)
{
	if (a.field1 > b.field1) {
		return -1;
	}
	else if (equals(a, b)) {
		return 0;
	}
	else {
		return 1;
	}
}

int equals(myType a, myType b)
{
	if (a.field1 == b.field1) {
		return 1;
	}
	else {
		return 0;
	}
}

/**
myType sum(myType a, myType b)
{
	return;
}

myType subtract(myType a, myType b)
{
	return;
}

myType multiply(myType a, myType b)
{
	return;
}

myType divide(myType a, myType b)
{
	return;
}
*/
