/**
*
*	Libreria di supporto all'esame di Fondamenti di Informatica 1 del corso di Ingegneria Informatica UNIBO
*
*	Si tratta dell'implementazione originale di Misclib.h, si tratta delle implementazione più veloce e leggibile possibile, non ci sono complessi usperflui e alcun virtuosismo
*	le funzioni sono state testate e funzionano per tutti i testcase testati. Dove era possibile scegliere è stato scelto ovviamente un approccio iterativo e non ricorsivo, in quanto più efficiente e meno pericoloso.
* 
*	@author:	leodom01
*	@GitHub:	https://github.com/Leodom01
*	@version:	0.1
*
*	Visit my GitHub page to download the last version of the lib
*	For problems or infos please contact me at: leonardodominici01@gmail.com
*/

#include "Misclib.h"
#include <math.h>

double myMin(double a, double b){

	if (a < b) {
		return a;
	}else if (a > b) {
		return b;
	}else {
		return 0;
	}
}

double myMax(double a, double b) {

	if (a > b) {
		return a;
	}
	else if (a < b) {
		return b;
	}
	else {
		return 0;
	}
}

int mcd(int a, int b){
	a = abs(a);
	b = abs(b);
	int r;
	r = a % b;
	while (r > 0){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int mcm(int a, int b){
	a = abs(a);
	b = abs(b);
	return (a * b) / mcd(a, b);
}

void msToTime(int* ms, int* sec, int* min){
	*ms = abs(*ms);
	*sec = *ms / 1000;
	*ms = *ms % 1000;
	*min = *sec / 60;
	*sec = *sec % 60;
	return;
}

int contaCifre(int n){
	int cifre = 0;
	n = abs(n);
	if (n == 0) {
		return 0;
	}else{
		while (n >= 1) {
			n = n / 10;
			cifre++;
		}
	}
	return cifre;
}

int invertiNum(int n){
	int inv = 0;
	int cifre = contaCifre(n);
	for (int i = cifre; i > 0; i--) {
		inv = inv + n % 10 * (int)pow(10, (double)i - 1);
		n = n / 10;
	}
	return inv;
}
