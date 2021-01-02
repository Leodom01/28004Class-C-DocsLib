/**
*
*	Libreria per definire un tipo di dato custom a cui collegare più funzioni di base, crea anche i puntatori per aggiungere una lista di struct del tipo che
*	definisco in questa libreria, per usare tutte le funzioni fornite nella altre libreria ricordarsi di implementare i metodi sotto elencati, servono per
*	sorting, comparazioni e altre funzioni varie.
*
*	la libreria contiene il prototipo per creare al volo nuove struct e lista contenenti la struct appena creata, è poi necesario implementare le funzioni sotto
*	elencate se si vogliono usare tutti i metodi forniti nella altre librerie siccome quelle libreria si potrebbero appoggiare a questi metodi
*
*	@author:	leodom01
*	@GitHub:	https://github.com/Leodom01
*	@version:	0.1
*
*	Visit my GitHub page to download the last version of the lib
*	For problems or infos please contact me at: leonardodominici01@gmail.com
*/

#pragma once
#include<stdlib.h>

//Definisco la mia struct con un tipo custom
typedef struct {
	int field1;
} myType;

//Definisco un elemento della mia lista contenente elemeni myType
typedef struct item_struct{
	myType value;
	struct item_struct* next;
} item;

//Definisco il puntatore alla mia lista, ovvero il primo elemento
typedef item* root;

//In base all'utilizzo che verrà fatto della struct decidere se implementare o meno e come implementare caso per caso le seguenti funzioni
/**
//Stampa l tipo myType in base a come lo implemento, stampa a console
void printMytype(myType target);

//Ritorna 1 se sono uguali o 0 se non lo sono
int equals(myType a, myType b);

//Ritorna -1 se a è maggiore, 0 se sono uguali, 1 se b è maggiore
int compare(myType a, myType b);

//Classiche operazioni algebriche che potrebbero dover essere implementate
myType sum(myType a, myType b);
myType subtract(myType a, myType b);
myType multiply(myType a, myType b);
myType divide(myType a, myType b);
*/
