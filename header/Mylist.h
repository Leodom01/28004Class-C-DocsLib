/**
*
*	Libreria di utility varie per liste di dati myType per l'esame di Fondamenti di Informatica 1 del corso di Ingegneria Informatica UNIBO
*	Molte delle funzioni sotto elencate richiedono l'implementazione completa delle funzioni in myType siccome alcune funzioni richiedono di poter
*	comparare fra loro oggetti o di effettuare somme, o comunque lavorare con questi tipi di fati custom
*
*	La libreria contiene una serie di funzioni utili per lavorare con le liste e ne aumenta l'astrazione così da non dover stare a lavorare
*	troppo con puntatori e concetti vari, per usare le liste ora basterà solo creare il puntatore al primo elemento della lista e modificare
*	myType.h con il tipo di dato con cui vogliamo operare, dopodichè implementando le poche funzioni su myType.h tutto funzionerà senza problemi
*	(molte delle funzioni qui presenti sono state prese direttamente dalle funzioni proposte nelle librerie List standard di Java)
*
*	@author:	leodom01
*	@GitHub:	https://github.com/Leodom01
*	@version:	0.1
*
*	Visit my GitHub page to download the last version of the lib
*	For problems or infos please contact me at: leonardodominici01@gmail.com
*/

#include "Mytype.h"
//Crea una nuova lista vuota e ne ritorna il puntatore, ovviamente punta a NULL next siccome non c'è nessun elemento
root newList();

//Dice se la lista è vuota e quindi non ha elementi o se ne ha anche solo 1
int isEmpty(root first_elem);

//restituisce il primo elemento della lista
myType head(root first_elem);

//restituisce il puntatore a tutta la lista partendo dal secondo elemento , il primo escluso
root tail(root first_elem);

//Aggiunge un elemento in testa alla lista
root add(myType new_elem, root first_elem);

//Stampa la lista
void printList(root first_elem);

//Restituisce l'elemento alla posizione index
myType get(root first_elem, int index);

//Restituisce la prima occorrenza del first_elem
int find(myType elem, root first_elem);

//Restituisce il numero di elementi presenti nella lista
int lenght(root first_elem);

//Crea una lista appendendo la seconda lista alla coda della prima, non copio di nuovo i valori quindi c'è structure sharing
root append(root first_elem_1, root first_elem_2);

//Esegue una copia completa della lista e ritorna un puntatore ad una lista identica ma in un'altra zona di memoria, quindi non c'è structure sharing
root newCopy(root first_elem);

//Capovolge una lista
root reverse(root first_elem);

//Cancella completamente la lista facendo la free di tuti i suoi elementi ad eccezione del puntatore ovviamente
void destroy(root first_elem);

//Mette a NULL tutti i valori val della lista, restano i riferimenti a next
void setNull(root first_elem);

//Restituisce l'ultima occorrenza di elem
int lastIndexOf(root first_elem, myType elem);

//Rimuove la prima occorrenza dell'elemento elem
void remove(root first_elem, myType elem);

//Crea una copia della sottolista e ne restituisce il root (puntatore al primo elemento), non c'è structure sharing
root subList(root first_elem, int start_index, int end_index);

//Riempie un'array di dimensioni opportune con tutti gli elementi della lista, occhio a passargli un array della dimensione giusta
myType* fillArray(root first_elem, int* arr);

//Aggiunge un elemento alla posizione index della lista, se è 0 lo aggiunge in testa, se è 1 lo aggiunge al primo posto e così via
void addAt(root first_elem, myType elem, int index);

//Cancella l'elemento all'indice index
void removeIndex(root first_elem, int index);

//Scambia il valore di due elementi
void swapElem(root first_elem, int first_index, int second_index);

//esegue il naive sort sulla lista
void naiveSort(root first_elem);

//Esegue il bubble sort sulla lista
void bubbleSort(root first_elem);

//Esegue l'insert sort sulla lista
void insertSort(root first_elem);

//Esegue il merge sort sulla lista
void mergeSort(root first_elem);

//Esegue il quicksort sulla lista
void quickSort(root first_elem);
