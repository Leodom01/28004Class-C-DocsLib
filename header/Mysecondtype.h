/**
*
*	Libreria per definire un tipo di dato custom aggiuntivo rispetto a Mytype.h, spesso è necessario in quanto vengono richiesti due dati custom differenti.
* Il primo, il dato principale dovrebbe essere Mytype.h, permettendo di implementare anche le liste, questo secondo tipo di dato è un po' più scarno ma
* siccome viene spesso usato è più comodo averlo già presente in caso di necessità. Implementa le funzioni come equals e compare relative quindi a operazioni
* sul dato ma non implementa le liste. Implementa però gli algoritmi di ordinamento su array.
*
*	la libreria contiene il prototipo per creare al volo nuove struct e lista contenenti la struct appena creata, è poi necesario implementare le funzioni sotto
*	elencate se si vogliono usare tutti i metodi forniti nella altre librerie siccome quelle libreria si potrebbero appoggiare a questi metodi.
* Alcune delle funzioni sono brutalmente commentate siccome ritenevo rilevante presentarle ma spesso non sono necessarie e per velocizzare
* lo sviluppo durante l'esame ho deciso di commentarle così che non sia obbligatorio implementarle.
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

//Definisco un secondo tipo di dato che serve di solito all'esame senza bisogno che esso implementi liste, spesso ne servono array e il loro ordinamento
typedef struct{
	int fieldA;
} mySecondType;

//Vari tipi di operazioni da effettuars
/**
*	Stampa il tipo mySecondType in base a come lo implemento, stampa a console
*
* @param target: 	La variabile che devo stampare a console
*/
//void printMySecondType(mySecondType target);

/**
* Ritorna 1 se sono uguali o 0 se non lo sono (Secondo i parametri che implemento)
*
* @param a:				Il primo dei due elementi da confrontare
* @param b:				Il secondo dei due elementi da confrontare
*
* @return 0:			Se i due elementi non sono uguali
* @return 1:			Se i due elementi sono uguali
*/
//int equalsMySecondType(mySecondType a, mySecondType b);

/**
* Ritorna -1 se a è maggiore, 0 se sono uguali, 1 se b è maggiore
*
* @param a				Il primo dei due elementi da confrontare
* @param b:				Il secondo dei due elementi da confrontare
*
* @return -1:			Se a è maggiore di b
* @return  0:			Se a è uguale a b
* @return  1:			Se a è minore di b
*/
//int comparemySecondType(mySecondType a, mySecondType b);
