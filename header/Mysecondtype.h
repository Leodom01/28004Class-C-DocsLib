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
typedef struct {
	int fieldA;
} mySecondType;

//Vari tipi di operazioni da effettuars
/**
*	Stampa il tipo mySecondType in base a come lo implemento, stampa a console
*
* @param target: 	La variabile che devo stampare a console
*/
void printMySecondType(mySecondType target);

/**
* Ritorna 1 se sono uguali o 0 se non lo sono (Secondo i parametri che implemento)
*
* @param a:				Il primo dei due elementi da confrontare
* @param b:				Il secondo dei due elementi da confrontare
*
* @return 0:			Se i due elementi non sono uguali
* @return 1:			Se i due elementi sono uguali
*/
int equalsMySecondType(mySecondType a, mySecondType b);

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
int compareMySecondType(mySecondType a, mySecondType b);

/**
* Stampa un'array di dim elementi di mySecondType, usa l'implementazione di printMySecondType
*
* @param *arr:	Il puntatore all'array di mySecondType
* @param dim:	Il numero di elementi di *arr
*/
void printArrMySecondType(mySecondType* arr, int dim);

/**
* Funzione utilizzata dentro agli algortmi di sorting, scambia semplicemente di due valori passati
*
* @param *a:	Il primo valore da scambiare
* @param *b:	Il secondo valore
*/
void scambiaMySecondType(mySecondType* a, mySecondType* b);

/**
* Cerca l'elemento maggiore e ne restituisce l'indice
*
* @param v[]:	L'array in cui effettuare una ricerca
* @param n:		La dimensione massimo dell'array
*/
int trovaPosMaxMySecondType(mySecondType v[], int n);

/**
* Determina la posizione in cui va inserito il valore e lo inserisce muovendo il resto dell'array, viene usata solo in insert sort
*
* @pram v[]:	L'array dentro cui inserire in modo corretto l'elemento
* @param pos:	La posizione a cui si trova l'elemento da inserire
*/
void insOrdMySecondType(mySecondType v[], int pos);

/**
* Esegue un sorting dell'array tramite l'algoritmo Naive Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void naiveSortMySecondType(mySecondType* arr, int size);

/**
* Esegue un sorting dell'array tramite l'algoritmo Bubble Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void bubbleSortMySecondType(mySecondType* arr, int size);

/**
* Esegue un sorting dell'array tramite l'algoritmo Insert Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void insertSortMySecondType(mySecondType* arr, int size);

/**
* Funzione usata in mergeSort che fa il vero hard work, serve a fondere in modo ordinato i sub-array
*
* Non ho ben capito a cosa servano tutti i parametri, eventualmente chiedi al tutorz.
*/
void mergeMySecondType(mySecondType v[], int i1, int i2, int fine, mySecondType vout[]);

/**
* Si tratta di una funzione che viene impacchettata dentro mergeSort per poter usare ricorsivamente mergeSortInner senza dover inserire parametri non essenziali a mergeSort
*
* @param v[]:	Il vettore da ordinare
* @param first:	Il primo elemento del vettore da ordinare (quando è impacchettata equivale a 0)
* @param last:	L'ultimo elemento del vettore da ordinare (quando è impacchettata equivale a size del vettore)
* @param vout[]:Il vettore di uscita già ordinato
*/
void mergeSortInnerMySecondType(mySecondType v[], int first, int last, mySecondType vout[]);

/**
* Esegue un sorting dell'array tramite l'algoritmo Merge Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void mergeSortMySecondType(mySecondType* in_arr, int size, mySecondType* out_arr);

/**
* Si tratta della vera funzione di quicksort che però ha troppi parametri non usati e quindi viene impaccehttata dentro quicksort che la invoca con iniz = 0 e fine = size
*
* @param a[]:	L'array da ordianre
* @param iniz:	Il primo elemento da ordianate (quando viene invocata dalla quickSort sarà = 0)
* @param fine:	L'ultimo elemento dell'array da ordinare (quando viene invocata dalla quickSort sarà = 0)
*/
void quickSortInnerMySecondType(mySecondType a[], int iniz, int fine);

/**
* Esegue un sorting dell'array tramite l'algoritmo Quick Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void quickSortMySecondType(mySecondType* arr, int size);
