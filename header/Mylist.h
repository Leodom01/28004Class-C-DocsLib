/**
*	Dominici Leonardo Matricola: 0000971128 Prova:
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
#pragma once
#include "Mytype.h"
#include <stdlib.h>

/**
* Crea semplicemente una nuova lista ritornando NULL, il NULL è da inserire al puntatore root del primo elemento, il puntatore al primo elemnto è null
* siccome non è ancora stat creata alcuna lista
*
* @return root:			L'elemento da assegnare al puntatore alla lista (ovvero NULL)
*/
root newList();

/**
* Indica se la lista è vuota, la lista vuota ha NULL come val in tutti i nodi, i vari nodi possono esistere e possono essere collegati fra loro ma se il valore degli
* elementi che contengono è = NULL allora la lista è vuota, anche se la lista non ha alcun elemento è vuota
* in quanto non si può assegnare a un value il valore NULL questo metodo è superfluo, on serve a nulla
* Se item->value potesse essere NULL avrebbe senso
*
* @param first_elem:	Il puntatore al primo elemento della lista
*
* @return 1:			Se la lista è vuota
* @return 0:			Se la lista ha elementi != NULL
* @return -1:			Se la lista è NULL
*/
int isEmpty(root first_elem);

/**
* Restituisce il valore del primo elemento della lista, quindi non il nodo, non Item ma il vlaore vero e proprio
*
* @param first_elem:	Il puntatore al primo elemento della lista
*
* @return:				Il primo elemento della lista (il value dell'item nella prima posizione)
* @return exit(-2):			Se la lista è vuota
*/
myType head(root first_elem);

/**
* Restituisce la lista eccetto il primo elemento, per l'esattezza restituisce il puntatore al secondo elemento della lista, ma lo restituisce come se
* fosse il primo elemento di una nuova lista, infatti p di tipo root
*
* @param first_elem:	Il puntatore alla lista
*
* @return :				Il puntatore al secondo elemento della lista
* @return exit(-3):			Se la lista ha 1 o nessun elemento
*/
root tail(root first_elem);

/**
* Aggiunge un elemento in testa alla lista
*
* @param new_elem:		Il nuovo elemento di tipo myType da aggiungere in testa
* @param first_elem:	Il puntatore alla lista (ovvero al suo primo elemento)
*
* @return :				Il puntatore alla lista con aggiunto il nuovo elemento (quindi il puntatore al nuovo elemento aggiunto), ritorna il puntatore alla lista con l'elemento aggiunto di fresco
* @return exit(-6):		Non è andata a buon fine la malloc
*/
root add(myType new_elem, root first_elem);

/**
* Stampa sequenzialmente tutti i valori della lista, per stampare il tipo di dato mytype sfrutta l'implementazione fatta in myType.c
*
* @param first_elem:	Il puntatore alla lista
*
* @custom:				Facilente customizzabile andando a cambiare il modo in cui la lista viene stampata
*/
void printList(root first_elem);

/**
* Restituisce l'elemento index della lista, ovvero l'elemento all'indice index (index = 0 primo elemento, index = 2 terzo elemento...)
*
* @param first_elem:	Il puntatore alla lista
* @param index:			L'indice del valore che voglio ritornare
*
* @return :				L'elemento trovato all'indice index
* @return exit(-4):		Se alla posizione index non c'è alcun elemento o se il valore dell'item index è NULL
*/
myType get(root first_elem, int index);

/**
* Restituisce il puntatore all'elemento numero index della lista
*
* @param first_elem:	Il puntatore alla lista
* @param index:			L'indice dell'elemento di cui voglaimo ritornare il puntatore
*
* @return :				Il puntatore all'elemento
* @return NULL:			Se la lista è vuota o se non esiste l'elemento numero index
*/
item* getPointer(root first_elem, int index);

/**
* Restituisce l'indice della prima occorrenza di un dato myType, deve essere implementata la funzione equals di myType
*
* @param elem:			L'elemento da ricercare nella lista
* @param first_elem:	Il puntatore alla lista
*
* @return :				L'indice a cui si trova la prima occorrenza di elem
* @return -1:			Se elem non è presente dentro la lista o se la lista è NULL
*/
int find(myType elem, root first_elem);

/**
* Restituisce la lunghezza della lista, anche se ci sono degli item con valore null vengono contati
*
* @param first_elem:	Il puntatore alla lista
*
* @return 0:			Se la lista è vuota (NULL)
* @return :				Il numero degli elementi della lista (il numero delle celle della lista assegnate)
*/
int lenght(root first_elem);

/**
* Appende malamente due liste, appende la seconda lita in coda alla prima, occhio perchè c'è structure sharing
*
* @param first_elem_1:	Il puntatore alla prima lista, quella a cui appendere la seconda
* @param first_elem_2:	Il puntatore alla seconda lista, quella che verrà appesa all'ultimo elemento della prima
*
* @return :				Il puntatore alla lista somma delle due, si tratta sempre del puntatore alla prima lista
*/
root append(root first_elem_1, root first_elem_2);

/**
* Copia una lista in un'altra area di memoria e poi restituisce il puntatore alla nuova lista, non c'è structure sharing, nessuna delle due liste viene cancellata
*
* @param first_elem:	Il puntatore alla lista da copiare
*
* @return :				il puntatore alla nuova lista creata in memoria
* @return exit(-5):		Se non riesce a fare una malloc
*/
root newCopy(root first_elem);

/**
* Scambia il valore di due elementi dentro ad una lista, scambia solo il valore dell'Item, non lavora con gli indici
*
* @param first_elem:	Il puntatore alla lista
* @param first_index:	L'indice del primo elemento da scambiare
* @parm second_index:	L'indice del secondo elemento da scambiare
*/
void swapElem(root first_elem, int first_index, int second_index);

/**
* Capovolge interamente una lista dal primo all'ultimo elemento (l'ultimo valore diventa il primo, il penultimo diventa secondo...)
*
* @param first_elem:	Il puntatore alla lista
*/
void reverse(root first_elem);

/**
* Cancella completamente la lista facendo la free di ogni suo elemento, trasforma il puntatore alla lista in NULL in quanto la lista è vuota
*
* @param first_elem:	Il puntatore alla lista per riferimento perchè va trasformato in NULL
*/
void destroy(root* first_elem);

/**
* Restituisce l'indice della ultima occorrenza di un dato myType, oppure la prima occorrenza partendo dal fondo
*
* @param first_elem:	Il puntatore alla lista
* @param elem:			L'elemento del quale vogliamo conoscere l'unica occorrenza
*
* @return :				L'indice dell'ultima occorrenza di un elemento
* @return -1:			Se l'elemento non è presente nella lista
*/
int lastIndexOf(root first_elem, myType elem);

/**
* Rimuove la prima occorrenza dell'elemento all'interno della lista, effettua la rimozione con una free, elimina totalmente quel nodo dalla memoria
*
* @param first_elem:	Il puntatore della lista per riferimneto (siccome nel caso in cui fosse il primo elemento da cancellare il puntatore alla lsita dovrebbe cambiare
* @param elem:			L'elemento del quale cancellare il primo nodo
*/
void deleteOcc(root* first_elem, myType elem);

/**
* Crea una sottolista della lista data a partire da un dato elemento e poi ne restituisce il puntatore, non c'è structure sharing. Se l'indice di inizio non è presente nella lista
* verrà ritornato NULL
*
* @param first_elem:	Il puntatore alla lista
* @param start_index:	L'indice da cui partire a creare la sottolista
* @param end_index:		L'indice a cui far terminare la sottolista
*
* @return :				Il puntatore alla sottolista
* @return NULL:			Se la lista di cui fare la sottolista è vuota
* @return exit(-8):		Se gli estremi della sottolista sono sbagliati
*/
root subList(root first_elem, int start_index, int end_index);

/**
* Riempie un'array con tutti gli elementi della lista, occhio a fornire un'array di dimensione sufficientemente grande
* Ritorna poi il numero di elementi inseriti dentro l'array
*
* @param first_elem:	Il puntatore alla lista
* @param *arr:			Il puntatore al primo elemento dell'array da riempire
* @param size:			La dimensione dell'array da riempire
*
* @return :				Il numero di elementi che sono stati inseriti nell'array
* @return -1:			Se la dimensione dell'array non è abbastanza grande per contenere tutti gli elementi della lista
*/
int fillArray(root first_elem, myType* arr, int arr_size);

/**
* Aggiunge un elemento all'indice index della lista (se lo agigungiamo all'index 0 lo aggiunge in testa, se lo aggiungiamo a index = 3 lo aggiunge come quarto elemento)
* Se l'indice a cui vogliamo aggiungere l'elemento è superiore alla dimensione della lista allora l'elemento verrà aggiunto in fondo
*
* @param first_elem:	Il puntatore alla lista a cui aggiungere l'elemento
* @param elem:			L'elemento da aggiungere alla lista
* @param index:			L'indice in cui aggiungere l'elemento alla lista
*
* @return exit(-7):		Se quell'indice non esiste o se la lista è NULL, o la malloc è fallita
*/
void addAt(root* first_elem, myType elem, int index);

/**
* Cancella l'elemento all'indice index della lista, fa la free sulla sua cella e poi riattacca tutti gli elementi dopo di lui alla lista
*
* @param first_elem:	Il puntatore alla lista
* @param index:			L'indice della cella da distruggere
*
* @return -1:			Se non esiste quell'indice in quella list
* @return -2:			Se la lista è null
* @return 1:			Tutto è andato bene
*/
int removeIndex(root* first_elem, int index);

/**
* Dato un array di dati myType la funzione ritorna il puntatore ad una lista formata dagli elementi dell'array
*
* @param arr[]:			L'array dal quale prendere gli elementi da mettere nella lista
* @param dim:			La dimensione dell'array
*
* @return NULL:			Se l'array è vuoto
* @return :				Il puntatore alla lista che contiene tutti gli elementi dell'array
*/
root arrayToList(myType arr[], int dim);

/**
* Esegue il naive sort sulla lista, è necessario implementare la funzione compare in myType.c
*
* @param first_elem:	Il puntatore alla lista
*/
void naiveSort(root first_elem);

/**
* Esegue il bubble sort sulla lista, è necessario implementare la funzione compare in myType.c
*
* @param first_elem:	Il puntatore alla lista
*/
void bubbleSort(root first_elem);

/**
* Esegue l'insert sort sulla lista, è necessario implementare la funzione compare in myType.c
*
* @param first_elem:	Il puntatore alla lista
*/
void insertSort(root first_elem);

/**
* Esegue il merge sort sulla lista, è necessario implementare la funzione compare in myType.c
*
* @param first_elem:	Il puntatore per riferimento alla lista, siccome durante il processo creo un'altra lista, resterà solo quella ordinata
*/
void mergeSort(root* first_elem);

/**
* Esegue il quick sort sulla lista, è necessario implementare la funzione compare in myType.c
*
* @param first_elem:	Il puntatore alla lista
*/
void quickSort(root first_elem);
