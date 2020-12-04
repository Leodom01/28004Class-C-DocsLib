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
* @return		Il numero di valori effettivamente stampati
* 
* @custom		Si può modificare la stringa di accompagnamento del valore per mostrare all'utente un messaggio diverso, andando in Myarray.c
*/
int printArrInt(int* arr, int size);

/**
* Stampa tutti gli elementi dell'array in successione dall'elemento di indice 0 a quello di indice size-1
*
* @param *arr:	Il puntatore al primo valore dell'array di double da stampare
* @param size:	La dimensione dell'array da stampare, la stampa avverrà da arr[0] sino a arr[size-1]
*
* @return		Il numero di valori effettivamente stampati
*
* @custom		Si può modificare la stringa di accompagnamento del valore per mostrare all'utente un messaggio diverso, andando in Myarray.c
*/
int printArrDouble(double* arr, int size);

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
