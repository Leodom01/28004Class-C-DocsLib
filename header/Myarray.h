/**
*
*	Libreria di utility varie per array di int e di double per l'esame di Fondamenti di Informatica 1 del corso di Ingegneria Informatica UNIBO
*	Molte delle funzioni sono funzioni analoghe già presenti e implementate in string.h per le stringhe
*	Per un implementazione un po' più wise di array con tipi custom vedi MyarrayTypedef.h
*
*	La libreria contiene una serie di funzioni utili per operare con array di int e double, racchiude funzioni di input/output, ricerca, sorting...
*	Esiste anche l'implementazione di questo header file
*
*	@author:	leodom01
*	@GitHub:	https://github.com/Leodom01
*	@version:	0.1
*
*	Visit my GitHub page to download the last version of the lib
*	For problems or infos please contact me at: leonardodominici01@gmail.com
*/

/**
* Chiede un numero pari a size di elementi da inserire nell'array, se si digita 0 prima dei size valori il ciclo si interrompe, restituisce infine il numero di valori acquisiti (escluso il valore di terminazione dell'acquisizione)

*
* @param *arr:	Il puntatore al primo valore dell'array di int su cui scrivere
* @param size:	La dimensione massima dell'array
*
* @return		Il numero di valori inseriti nell'array, escluso il valore di termine acquisizione se presente (dimensione logica)
*
* @custom		Si può modificare il valore che fa terminare l'acquisizione, di default è 0, andando in Myarray.c può essere cambiato in quello che si preferisce, purchè sia un intero
* @custom		Si può modificare la stringa di testo che accompagna l'input al fine di mostrare un testo diverso all'utente
* @custom		Si possono decidere di non accettare alcuni valori, ad esempio si possono accettare solo gli interi positivi
*/
int inputArrInt(int* arr, int size);

/**
* Chiede un numero pari a size di elementi da inserire nell'array, se si digita 0 prima dei size valori il ciclo si interrompe, restituisce infine il numero di valori acquisiti (escluso il valore di terminazione dell'acquisizione)
*
*
* @param *arr:	Il puntatore al primo valore dell'array di double su cui scrivere
* @param size:	La dimensione massima dell'array
*
* @return		Il numero di valori inseriti nell'array, escluso il valore di termine acquisizione se presente (dimensione logica)
*
* @custom		Si può modificare il valore che fa terminare l'acquisizione, di default è 0, andando in Myarray.c può essere cambiato in quello che si preferisce, purchè sia un intero
* @custom		Si può modificare la stringa di testo che accompagna l'input al fine di mostrare un testo diverso all'utente, andando in Myarray.c
* @custom		Si possono decidere di non accettare alcuni valori, ad esempio si possono accettare solo gli interi positivi, andando in Myarray.c
*/
int inputArrDouble(double* arr, int size);

/**
* Stampa tutti gli elementi dell'array in successione dall'elemento di indice 0 a quello di indice size-1
*
* @param *arr:	Il puntatore al primo valore dell'array di int da stampare
* @param size:	La dimensione dell'array da stampare, la stampa avverrà da arr[0] sino a arr[size-1]
*
*
* @custom		Si può modificare la stringa di accompagnamento del valore per mostrare all'utente un messaggio diverso, andando in Myarray.c
*/
void printArrInt(int* arr, int size);

/**
* Stampa tutti gli elementi dell'array in successione dall'elemento di indice 0 a quello di indice size-1
*
* @param *arr:	Il puntatore al primo valore dell'array di double da stampare
* @param size:	La dimensione dell'array da stampare, la stampa avverrà da arr[0] sino a arr[size-1]
*
*
* @custom		Si può modificare la stringa di accompagnamento del valore per mostrare all'utente un messaggio diverso, andando in Myarray.c
*/
void printArrDouble(double* arr, int size);

/**
* Cerca l'elemento x nell'array di dimensione size, restituisce l'indice a cui si trova la prima occorrenza di x
*
* @param *arr:	Il puntatore al primo elemento dell'array di int in cui cercare x
* @param size:	La dimensione dell'array arr
* @param x:		Il valore da ricercare nell'array
*
* @return		L'indice della prima occorrenza di x dentro arr
* @return -1	Se l'elemento non è stato trovato
*/
int searchElemInt(int* arr, int size, int x);

/**
* Cerca l'elemento x nell'array di dimensione size, restituisce l'indice a cui si trova la prima occorrenza di x
*
* @param *arr:	Il puntatore al primo elemento dell'array di double in cui cercare x
* @param size:	La dimensione dell'array arr
* @param x:		Il valore da ricercare nell'array
*
* @return		L'indice della prima occorrenza di x dentro arr
* @return -1	Se l'elemento non è stato trovato
*/
int searchElemDouble(double* arr, int size, double x);

/**
* Compara due array valore per valore e indica se essi sono uguali, e in caso negativo quale dei due è maggiore, ovvero quello in cui è presente il valore maggiore fra i due valori diversi trovati a un indice i ([1, 2, 3, 5] e [1, 2, 3, 6] il secondo è maggiore)
*
* @param *arr1	Il puntatore al primo array da comparare
* @param size1	La dimensione del primo array
* @param *arr2	Il puntatore al secondo array da comparare
* @param size2	La dimensione del secondo array
*
* @return 0		Se i due array hanno gli stessi valori negli stessi indici
* @return -1	Se il primo array ha il carattere discorde maggiore o se l'array è di dimensione maggiore
* @return 1		Se il secondo array ha il carattere discorde maggiore o se l'array è di dimensione maggiore
*/
int arrCompareInt(int* arr1, int size1, int* arr2, int size2);

/**
* Compara due array valore per valore e indica se essi sono uguali, e in caso negativo quale dei due è maggiore, ovvero quello in cui è presente il valore maggiore fra i due valori diversi trovati a un indice i ([1, 2, 3, 5] e [1, 2, 3, 6] il secondo è maggiore)
*
* @param *arr1	Il puntatore al primo array da comparare
* @param size1	La dimensione del primo array
* @param *arr2	Il puntatore al secondo array da comparare
* @param size2	La dimensione del secondo array
*
* @return 0		Se i due array hanno gli stessi valori negli stessi indici
* @return -1	Se il primo array ha il carattere discorde maggiore o se l'array è di dimensione maggiore
* @return 1		Se il secondo array ha il carattere discorde maggiore o se l'array è di dimensione maggiore
*/
int arrCompareDouble(double* arr1, int size1, double* arr2, int size2);

/**
* Conta quante occorrenze di un elemento ci sono in un array, ovvero quante volte x è ripetuto in arr
*
* @param *arr:	L'array in cui cercare le ripetizioni di x
* @param size:	La dimensione dell'array
* @param x:		Il valore di cui cercare le occorrenze
*
* @return		Il numero delle occorrenze di x in arr
*/
int countOccurrInt(int* arr, int size, int x);

/**
* Conta quante occorrenze di un elemento ci sono in un array, ovvero quante volte x è ripetuto in arr
*
* @param *arr:	L'array in cui cercare le ripetizioni di x
* @param size:	La dimensione dell'array
* @param x:		Il valore di cui cercare le occorrenze
*
* @return		Il numero delle occorrenze di x in arr
*/
int countOccurrDouble(double* arr, int size, double x);

/**
* Funzione utilizzata dentro agli algortmi di sorting, scambia semplicemente di due valori passati
*
* @param *a:	Il primo valore da scambiare
* @param *b:	Il secondo valore
*/
void scambiaInt(int* a, int* b);

/**
* Cerca l'elemento maggiore e ne restituisce l'indice
*
* @param v[]:	L'array in cui effettuare una ricerca
* @param n:		La dimensione massimo dell'array
*/
int trovaPosMaxInt(int v[], int n);

/**
* Determina la posizione in cui va inserito il valore e lo inserisce muovendo il resto dell'array, viene usata solo in insert sort
*
* @pram v[]:	L'array dentro cui inserire in modo corretto l'elemento
* @param pos:	La posizione a cui si trova l'elemento da inserire
*/
void insOrdInt(int v[], int pos);

/**
* Esegue un sorting dell'array tramite l'algoritmo Naive Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void naiveSortInt(int* arr, int size);

/**
* Esegue un sorting dell'array tramite l'algoritmo Bubble Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void bubbleSortInt(int* arr, int size);

/**
* Esegue un sorting dell'array tramite l'algoritmo Insert Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void insertSortInt(int* arr, int size);

/**
* Funzione usata in mergeSort che fa il vero hard work, serve a fondere in modo ordinato i sub-array
*
* Non ho ben capito a cosa servano tutti i parametri, eventualmente chiedi al tutorz.
*/
void mergeInt(int v[], int i1, int i2, int fine, int vout[]);

/**
* Si tratta di una funzione che viene impacchettata dentro mergeSort per poter usare ricorsivamente mergeSortInner senza dover inserire parametri non essenziali a mergeSort
*
* @param v[]:	Il vettore da ordinare
* @param first:	Il primo elemento del vettore da ordinare (quando è impacchettata equivale a 0)
* @param last:	L'ultimo elemento del vettore da ordinare (quando è impacchettata equivale a size del vettore)
* @param vout[]:Il vettore di uscita già ordinato
*/
void mergeSortInnerInt(int v[], int first, int last, int vout[]);

/**
* Esegue un sorting dell'array tramite l'algoritmo Merge Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void mergeSortInt(int* in_arr, int size, int* out_arr);

/**
* Si tratta della vera funzione di quicksort che però ha troppi parametri non usati e quindi viene impaccehttata dentro quicksort che la invoca con iniz = 0 e fine = size
*
* @param a[]:	L'array da ordianre
* @param iniz:	Il primo elemento da ordianate (quando viene invocata dalla quickSort sarà = 0)
* @param fine:	L'ultimo elemento dell'array da ordinare (quando viene invocata dalla quickSort sarà = 0)
*/
void quickSortInnerInt(int a[], int iniz, int fine);

/**
* Esegue un sorting dell'array tramite l'algoritmo Quick Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void quickSortInt(int* arr, int size);

/**
* Cerca l'elemento maggiore e ne restituisce l'indice
*
* @param v[]:	L'array in cui effettuare una ricerca
* @param n:		La dimensione massimo dell'array
*/
int trovaPosMaxDou(double v[], int n);

/**
* Funzione utilizzata dentro agli algortmi di sorting, scambia semplicemente di due valori passati
*
* @param *a:	Il primo valore da scambiare
* @param *b:	Il secondo valore
*/
void scambiaDou(double* a, double* b);

/**
* Determina la posizione in cui va inserito il valore e lo inserisce muovendo il resto dell'array, viene usata solo in insert sort
*
* @pram v[]:	L'array dentro cui inserire in modo corretto l'elemento
* @param pos:	La posizione a cui si trova l'elemento da inserire
*/
void insOrdDou(double v[], int pos);

/**
* Funzione usata in mergeSort che fa il vero hard work, serve a fondere in modo ordinato i sub-array
*
* Non ho ben capito a cosa servano tutti i parametri, eventualmente chiedi al tutorz.
*/
void mergeDou(double v[], int i1, int i2, int fine, double vout[]);

/**
* Si tratta di una funzione che viene impacchettata dentro mergeSort per poter usare ricorsivamente mergeSortInner senza dover inserire parametri non essenziali a mergeSort
*
* @param v[]:	Il vettore da ordinare
* @param first:	Il primo elemento del vettore da ordinare (quando è impacchettata equivale a 0)
* @param last:	L'ultimo elemento del vettore da ordinare (quando è impacchettata equivale a size del vettore)
* @param vout[]:Il vettore di uscita già ordinato
*/
void mergeSortInnerDou(double v[], int first, int last, double vout[]);

/**
* Esegue un sorting dell'array tramite l'algoritmo Naive Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void naiveSortDouble(double* arr, int size);

/**
* Esegue un sorting dell'array tramite l'algoritmo Bubble Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void bubbleSortDouble(double* arr, int size);

/**
* Esegue un sorting dell'array tramite l'algoritmo Insert Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void insertSortDouble(double* arr, int size);

/**
* Esegue un sorting dell'array tramite l'algoritmo Merge Sort
*
* @param *in_arr:L'array da ordinare
* @param size:	La dimensione dell'array
* @param *out_arr:L'array di output
*/
void mergeSortDou(double* in_arr, int size, double* out_arr);

/**
* Si tratta della vera funzione di quicksort che però ha troppi parametri non usati e quindi viene impaccehttata dentro quicksort che la invoca con iniz = 0 e fine = size
*
* @param a[]:	L'array da ordianre
* @param iniz:	Il primo elemento da ordianate (quando viene invocata dalla quickSort sarà = 0)
* @param fine:	L'ultimo elemento dell'array da ordinare (quando viene invocata dalla quickSort sarà = 0)
*/
void quickSortInnerDou(double a[], int iniz, int fine);

/**
* Esegue un sorting dell'array tramite l'algoritmo Quick Sort
*
* @param *int:	L'array da ordinare
* @param size:	La dimensione dell'array
*/
void quickSortDou(double* arr, int size);
