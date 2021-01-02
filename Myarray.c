/**
*	Dominici Leonardo Matricola: 0000971128 Prova:
*	Libreria di supporto all'esame di Fondamenti di Informatica 1 del corso di Ingegneria Informatica UNIBO
*
*	Si tratta della libreria di implementazione originale alla Myarray.h, è una comoda implementazione per lavorare facilmente con array di int e di double, si possono usare facilmente anche i float apportando prima un cast
*	Per ragioni sintattiche legate al C i nomi delle funzioni sono piuttosto sconvenienti.
*
*	@author:	leodom01
*	@GitHub:	https://github.com/Leodom01
*	@version:	0.1
*
*	Visit my GitHub page to download the last version of the lib
*	For problems or infos please contact me at: leonardodominici01@gmail.com
*/

#include "Myarray.h"
#include <stdio.h>
#include <stdlib.h>

int inputArrInt(int* arr, int size)
{
	int flag = 0;
	int i = 0;
	do {
		printf("\nValore %d dell'array: ", i);
		int box;
		scanf_s("%d", &box);
		if (box != 0) {				//Qui ci metto i parametri che deve rispettare il mio input
			arr[i] = box;
			i++;
		}
		else {
			flag = 1;
		}
	} while (i < size && flag == 0);
	return i;
}

int inputArrDouble(double* arr, int size)
{
	int flag = 0;
	int i = 0;
	do {
		printf("\nValore %d dell'array: ", i);
		double box;
		scanf_s("%lf", &box);
		if (box != 0) {				//Qui ci metto i parametri che deve rispettare il mio input
			arr[i] = box;
			i++;
		}
		else {
			flag = 1;
		}
	} while (i < size && flag == 0);
	return i;
}

void printArrInt(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("\nValore %d dell'array: %d", i, arr[i]);
	}
}

void printArrDouble(double* arr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("\nValore %d dell'array: %lf", i, arr[i]);
	}
}

int searchElemInt(int* arr, int size, int x)
{
	int flag = 0;
	int val = -1;
	for (int i = 0; i < size && flag == 0; i++) {
		if (arr[i] == x) {
			val = i;
			flag = 1;
		}
	}
	return val;
}

int searchElemDouble(double* arr, int size, double x)
{
	int flag = 0;
	int val = -1;
	for (int i = 0; i < size && flag == 0; i++) {
		if (arr[i] == x) {
			val = i;
			flag = 1;
		}
	}
	return val;
}

int arrCompareInt(int* arr1, int size1, int* arr2, int size2)
{
	for (int i = 0; i < size1 && i<size2; i++) {
		if (arr1[i] > arr2[i]) {
			return -1;
		}
		else if (arr1[i] < arr2[i]) {
			return 1;
		}
	}
	if (size1 == size2) {
		return 0;
	}
	else if (size1 > size2) {
		return -1;
	}
	else{
		return 1;
	}
}

int arrCompareDouble(double* arr1, int size1, double* arr2, int size2)
{
	for (int i = 0; i < size1 && i < size2; i++) {
		if (arr1[i] > arr2[i]) {
			return -1;
		}
		else if (arr1[i] < arr2[i]) {
			return 1;
		}
	}
	if (size1 == size2) {
		return 0;
	}
	else if (size1 > size2) {
		return -1;
	}
	else{
		return 1;
	}
}

int countOccurrInt(int* arr, int size, int x)
{
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == x) {
			counter++;
		}
	}
	return counter;
}

int countOccurrDouble(double* arr, int size, double x)
{
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == x) {
			counter++;
		}
	}
	return counter;
}

void scambiaInt(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int trovaPosMaxInt(int v[], int n) {
	int i, posMax = 0;
	for (i = 1; i < n; i++)
		if (v[posMax] < v[i]) posMax = i;
	return posMax;
}

void insOrdInt(int v[], int pos)
{
	int i = pos - 1;
	int x = v[pos];
	while (i >= 0 && x < v[i]) {
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}
	v[i + 1] = x;
}

void naiveSortInt(int* arr, int size)
{
	int p;
	while (size > 1) {
		p = trovaPosMaxInt(arr, size);
		if (p < size - 1) {
			scambiaInt(&arr[p], &arr[size - 1]);
		}
		size--;
	}
}

void bubbleSortInt(int* arr, int size)
{
	int i, ordinato = 0;
	while (size > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < size - 1; i++)
			if (arr[i] > arr[i + 1]) {
				scambiaInt(&arr[i], &arr[i + 1]);
				ordinato = 0;
			}
		size--;
	}
}

void insertSortInt(int* arr, int size)
{
	int k;
	for (k = 1; k < size; k++)
		insOrdInt(arr, k);
}

void mergeInt(int v[], int i1, int i2, int fine, int vout[])
{
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (v[i] < v[j])
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) {
		vout[k] = v[i++]; k++;
	}
	while (j <= fine) {
		vout[k] = v[j++]; k++;
	}
	for (i = i1; i <= fine; i++) {
		v[i] = vout[i];
	}
}


void mergeSortInnerInt(int v[], int first, int last, int vout[])
{
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSortInnerInt(v, first, mid, vout);
		mergeSortInnerInt(v, mid + 1, last, vout);
		mergeInt(v, first, mid + 1, last, vout);
	}
}

void mergeSortInt(int* in_arr, int size, int* out_arr)
{
	mergeSortInnerInt(in_arr, 0, size-1, out_arr);
}

void quickSortInnerInt(int a[], int iniz, int fine)
{
	int i, j, iPivot, pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do{ /* trova la posizione del pivot */
			while (i < j && a[i] <= pivot) i++;
			while (j > i && a[j] >= pivot) j--;
			if (i < j) scambiaInt(&a[i], &a[j]);
		} while (i < j);
		if (i != iPivot && a[i] != a[iPivot])
		{
			scambiaInt(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortInnerInt(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortInnerInt(a, iPivot + 1, fine);
	}
}

void quickSortInt(int* arr, int size)
{
	quickSortInnerInt(arr, 0, size - 1);
}

int trovaPosMaxDou(double v[], int n) {
	int i, posMax = 0;
	for (i = 1; i < n; i++)
		if (v[posMax] < v[i]) posMax = i;
	return posMax;
}

void scambiaDou(double* a, double* b)
{
	double tmp = *a;
	*a = *b;
	*b = tmp;
}

void insOrdDou(double v[], int pos)
{
	int i = pos - 1;
	double x = v[pos];
	while (i >= 0 && x < v[i]) {
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}
	v[i + 1] = x;
}

void mergeDou(double v[], int i1, int i2, int fine, double vout[])
{
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (v[i] < v[j])
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) {
		vout[k] = v[i++]; k++;
	}
	while (j <= fine) {
		vout[k] = v[j++]; k++;
	}
	for (i = i1; i <= fine; i++) {
		v[i] = vout[i];
	}
}

void mergeSortInnerDou(double v[], int first, int last, double vout[])
{
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSortInnerDou(v, first, mid, vout);
		mergeSortInnerDou(v, mid + 1, last, vout);
		mergeDou(v, first, mid + 1, last, vout);
	}
}

void naiveSortDouble(double* arr, int size)
{
	int p;
	while (size > 1) {
		p = trovaPosMaxDou(arr, size);
		if (p < size - 1) {
			scambiaDou(&arr[p], &arr[size - 1]);
		}
		size--;
	}
}

void bubbleSortDouble(double* arr, int size)
{
	int i, ordinato = 0;
	while (size > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < size - 1; i++)
			if (arr[i] > arr[i + 1]) {
				scambiaDou(&arr[i], &arr[i + 1]);
				ordinato = 0;
			}
		size--;
	}
}

void insertSortDouble(double* arr, int size)
{
	int k;
	for (k = 1; k < size; k++)
		insOrdDou(arr, k);
}

void mergeSortDou(double* in_arr, int size, double* out_arr)
{
	mergeSortInnerDou(in_arr, 0, size - 1, out_arr);
}

void quickSortInnerDou(double a[], int iniz, int fine)
{
	int i, j, iPivot;
	double pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do { /* trova la posizione del pivot */
			while (i < j && a[i] <= pivot) i++;
			while (j > i && a[j] >= pivot) j--;
			if (i < j) scambiaDou(&a[i], &a[j]);
		} while (i < j);
		if (i != iPivot && a[i] != a[iPivot])
		{
			scambiaDou(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortInnerDou(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortInnerDou(a, iPivot + 1, fine);
	}
}

void quickSortDou(double* arr, int size)
{
	quickSortInnerDou(arr, 0, size - 1);
}
