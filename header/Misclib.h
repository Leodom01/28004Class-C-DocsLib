/**
* 
*	Libreria di supporto all'esame di Fondamenti di Informatica 1 del corso di Ingegneria Informatica UNIBO
* 
*	La libreria contiene una serie di definizione di funzioini di supprto che possono essere utili, inoltre fornisce uno spazio libero in cui inserire funzioni fatte al volo in sede d'esame
*	@author:	leodom01
*	@GitHub:	https://github.com/Leodom01
*	@version:	0.1
*	
*	Visit my GitHub page to download the last version of the lib
*	For problems or infos please contact me at: leonardodominici01@gmail.com
*/

/**
* Dati in ingresso due double restituisce il minore fra i due
* 
* @param a:		Primo double
* @param b:		Secondo double
* 
* @return Il minore fra i due double
* @return 0 Nel caso in cui i due double siano uguali
*/
double myMin(double a, double b);

/**
* Dati in ingresso due double restituisce il maggiore fra i due
*
* @param a:		Primo double
* @param b:		Secondo double
*
* @return		Il maggiore fra i due double
* @return 0		Nel caso in cui i due double siano uguali
*/
double myMax(double a, double b);

/**
* Dati in ingresso due dati INT ne restituisce l'MCD (massimo comun divisore)
* 
* @param a:		Primo INT
* @param b:		Secondo INT
* 
* @return		L'MCD fra i due numeri
* @return 1		Se i due numeri sono primi fra loro
*/
int mcd(int a, int b);

/**
* Dati in ingresso due dati INT ne restituisce l'MCM (minimo comune multiplo)
*
* @param a:		Primo INT
* @param b:		Secondo INT
*
* @return		L'MCM fra i due numeri
*/
int mcm(int a, int b);

/**
* Converte un tempo da millisecondi in millisecondi, secondi e minuti (128010 ms -> 10 ms, 8 sec, 2 min). Se il numero è negativo lo fa diventare positivo
* 
* @param ms:	Il puntatore di un INT alla zona di memoria dei millisecondi in ingresso, dopo la chiamata della funzione verrà modificata alla luce della divisione dei millisecondi iniziali in ms, sec e min. Dopo la chiamata i ms saranno <1000
* @param sec:	Il puntatore di un INT alla zona di memoria dei secondi, dopo la chiamata della funzione verrà riempita con il numero di sec (<60) corrispondente al tempo in ms.
* @param min:	Il puntatore di un INT alla zona di memoria dei minuti, dopo la chiamata della funzione verrà riempita con il numero di minuti corrispondenti al tempo in ms.
* 
*/
void msToTime(int* ms, int* sec, int* min);

/**
* Conta le cifre di un dato INT, dal primo valore significativo che incontra sino al coefficiente del termine di grado 0. (0 equivale a 0 cifre)
* 
* @param n:		Il numero di cui contare le cifre
* 
* @return		Il numero di cifre contate
*/
int contaCifre(int n);

/**
* Invrete un numero intero (2048 -> 8402)
* 
* @param n:		Il numero del quale invertire le cifre
* 
* @return		Il numero n con le cifre invertite (nel caso un cui degli 0 siano in testa vengono omessi)
*/
int invertiNum(int n);
