/**
*	Dominici Leonardo Matricola: 0000971128 Prova:
*	Libreria di utility varie per liste di dati myType per l'esame di Fondamenti di Informatica 1 del corso di Ingegneria Informatica UNIBO
*	la libria sotto riportata è l'implementazione che ho trovato più ooportuna per le funzioni definite in mtList.h
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
#include "Mylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

root newList() {
	return NULL;
}

int isEmpty(root first_elem) {
	if (first_elem == NULL) {
		return -1;
	}
	else {
		item* pointer;
		pointer = first_elem;
		while (pointer->next != NULL) {
			if (&(pointer->value) != NULL) {
				return 0;
			}
			pointer = pointer->next;
		}
		return 1;
	}
}

myType head(root first_elem)
{
	if (first_elem == NULL) {
		exit(-2);
	}
	else {
		return first_elem->value;
	}
}


root tail(root first_elem)
{
	if (first_elem == NULL) {
		exit(-3);
	}
	if (first_elem->next == NULL) {
		exit(-3);
	}
	return first_elem->next;
}


root add(myType new_elem, root first_elem)
{
	item* toAdd;
	toAdd = (item*)malloc(sizeof(item));
	if (toAdd == NULL) {
		exit(-6);
	}
	toAdd->value = new_elem;
	if (first_elem == NULL) {
		toAdd->next = NULL;
	}
	else {
		toAdd->next = first_elem;
	}
	return toAdd;
}

void printList(root first_elem)
{
	item* pointer = first_elem;
	printf("Stampo la lista: \n");
	if (pointer == NULL) {
		printf("Lista vuota.\n");
	}
	else {
		while (pointer->next != NULL) {
			printMytype(pointer->value);
			pointer = pointer->next;
		}
		printMytype(pointer->value);
	}
}

myType get(root first_elem, int index)
{
	item* pointer = first_elem;
	int i = 0;
	while (pointer->next != NULL && i != index) {
		i++;
		pointer = pointer->next;
	}

	if (i == index) {
		return pointer->value;
	}
	else {
		exit(-4);
	}

}

item* getPointer(root first_elem, int index) {
	if (first_elem == NULL) {
		return NULL;
	}
	item* pointer = first_elem;
	int i = 0;
	while (pointer->next != NULL && i != index) {
		pointer = pointer->next;
		i++;
	}
	if (i != index) {
		return NULL;
	}
	else {
		return pointer;
	}
}

int find(myType elem, root first_elem)
{
	if (first_elem == NULL) {
		return -1;
	}
	item* pointer = first_elem;
	int index = 0;
	while (pointer->next != NULL) {
		if (equals(pointer->value, elem)) {
			return index;
		}
		pointer = pointer->next;
		index++;
	}
	if (equals(pointer->value, elem)) {
			return index;
	}
	return -1;
}

int lenght(root first_elem)
{
	int lenght = 0;
	if (first_elem == NULL) {
		return lenght;
	}
	lenght++;
	item* pointer = first_elem;
	while (pointer->next != NULL) {
		lenght++;
		pointer = pointer->next;
	}
	return lenght;
}

root append(root first_elem_1, root first_elem_2)
{
	if (first_elem_1 == NULL) {
		return first_elem_2;
	}
	if (first_elem_2 == NULL) {
		return first_elem_1;
	}

	item* pointer = first_elem_1;
	while (pointer->next != NULL) {
		pointer = pointer->next;
	}
	pointer->next = first_elem_2;

	return first_elem_1;
}

root newCopy(root first_elem)
{
	if (first_elem == NULL) {
		return NULL;
	}

	root newRoot = (item*)malloc(sizeof(item));
	if (newRoot == NULL) {
		exit(-5);
	}
	newRoot->value = first_elem->value;
	newRoot->next = NULL;
	item* newPointer = newRoot;
	item* pointer = first_elem;
	while (pointer->next != NULL) {
		pointer = pointer->next;
		newPointer->next = (item*)malloc(sizeof(item));
		if (newPointer->next == NULL) {
			exit(-5);
		}
		newPointer = newPointer->next;
		newPointer->value = pointer->value;
		newPointer->next = NULL;
	}
	return newRoot;
}

void swapElem(root first_elem, int first_index, int second_index)
{
	item* pointerA;
	item* pointerB;
	myType valA, valB;
	valA = get(first_elem, first_index);
	valB = get(first_elem, second_index);
	pointerA = getPointer(first_elem, first_index);
	pointerB = getPointer(first_elem, second_index);

	pointerA->value = valB;
	pointerB->value = valA;
}

void reverse(root first_elem)
{
	if (first_elem == NULL) {
		return;
	}
	int index_max = lenght(first_elem);
	index_max = (int)ceil(index_max / 2);
	for (int i = 0; i < index_max; i++) {
		swapElem(first_elem, i, lenght(first_elem) - (i + 1));
	}
}

void destroy(root* first_elem)
{
	item* pointer = *first_elem;

	if (*first_elem == NULL) {
		return;
	}
	while (pointer->next != NULL) {
		item* toKill = pointer;
		pointer = pointer->next;
		free(toKill);
	}
	free(pointer);
	*first_elem = NULL;
}

int lastIndexOf(root first_elem, myType elem)
{
	int index = -1;
	int len = lenght(first_elem);
	for (int i = 0; i < len; i++) {
		if (equals(elem, get(first_elem, i))) {
			index = i;
		}
	}

	return index;
}

void deleteOcc(root* first_elem, myType elem)
{
	int index = find(elem, *first_elem);
	if (index > -1) {
		removeIndex(first_elem, index);
	}
}

root subList(root first_elem, int start_index, int end_index)
{
	int len = lenght(first_elem);
	if (first_elem == NULL) {
		return NULL;
	}
	if (start_index < 0 || end_index < 0 || start_index >= len || end_index >= len) {
		exit(-8);
	}

	root newRoot = (item*)malloc(sizeof(item));
	if (newRoot == NULL) {
		exit(-7);
	}
	int index = start_index;
	item* pointer = newRoot;
	while (index <= end_index && index < len) {
		pointer->value = get(first_elem, index);
		if (index != end_index) {
			pointer->next = (item*)malloc(sizeof(item));
			if (pointer->next == NULL) {
				exit(-7);
			}
			pointer = pointer->next;
			index++;
		}
		else {
			pointer->next = NULL;
			index++;
		}
	}
	return newRoot;
}

int fillArray(root first_elem, myType* arr, int arr_size)
{
	if (first_elem == NULL) {
		return -1;
	}
	int len = lenght(first_elem);
	if (arr_size < len) {
		return -1;
	}
	for (int i = 0; i < len; i++) {
		arr[i] = get(first_elem, i);
	}
	return len;
}

void addAt(root* first_elem, myType elem, int index)
{
	if (first_elem == NULL || index > lenght(*first_elem)) {
		exit(-7);
	}
	else if (index == 0) {
		*first_elem = add(elem, *first_elem);
		return;
	}
	else if (index == lenght(*first_elem)) {
		item* toAdd = malloc(sizeof(item));
		if (toAdd == NULL) {
			exit(-7);
		}
		else {
			toAdd->value = elem;
			item* preIndex = getPointer(*first_elem, index - 1);
			preIndex->next = toAdd;
			toAdd->next = NULL;
			return;
		}
	}
	else {
		item* preIndex = getPointer(*first_elem, index - 1);
		item* postIndex = getPointer(*first_elem, index);
		item* toAdd = malloc(sizeof(item));
		if (toAdd == NULL) {
			exit(-7);
		}
		else {
			toAdd->value = elem;
			toAdd->next = postIndex;
			preIndex->next = toAdd;
		}
	}
}

int removeIndex(root* first_elem, int index)
{
	int len = lenght(*first_elem);
	if (first_elem == NULL) {
		return -2;
	}
	else if (index >= len) {
		return -1;
	}
	else if (index == 0) {
		item* toDel = *first_elem;
		*first_elem = getPointer(*first_elem, 1);
		free(toDel);
		return 1;
	}
	else if (index + 1 == len) {
		item* preToDel = getPointer(*first_elem, len - 2);
		item* toDel = preToDel->next;
		preToDel->next = NULL;
		free(toDel);
		return 1;
	}
	else {
		item* preToDel = getPointer(*first_elem, index - 1);
		item* toDel = preToDel->next;
		item* postToDel = toDel->next;
		preToDel->next = postToDel;
		free(toDel);
		return 1;
	}

}

root arrayToList(myType arr[], int dim) {
	root toReturn = newList();
	for (int i = 0; i < dim; i++) {
		toReturn = add(arr[i], toReturn);
	}

	return toReturn;
}

int trovaPosMax(root first_elem, int dim_to_consider) {
	int i, posMax = 0;
	int n = dim_to_consider;
	int test;
	for (i = 1; i < n; i++) {
		if ((test = compare(get(first_elem, posMax), get(first_elem, i))) == 1) {
			posMax = i;
		}
	}
	printf("%d", posMax);
	return posMax;
}

void insOrd(root first_elem, int pos)
{
	int i = pos - 1;
	myType x = get(first_elem, pos);
	while (i >= 0 && compare(x, get(first_elem, i)) == 1) {
		getPointer(first_elem, i+1)->value = getPointer(first_elem, i)->value; /* crea lo spazio */
		i--;
	}
	getPointer(first_elem, i + 1)->value = x;
}

void merge(root first_elem, int i1, int i2, int fine, root second_elem)
{
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compare(get(first_elem, i), get(first_elem, j)) == 1)
			getPointer(second_elem, k)->value = get(first_elem, i++);
		else
			getPointer(second_elem, k)->value = get(first_elem, j++);
		k++;
	}
	while (i <= i2 - 1) {
		getPointer(second_elem, k)->value = get(first_elem, i++);
		k++;
	}
	while (j <= fine) {
		getPointer(second_elem, k)->value = get(first_elem, j++);
		k++;
	}
	for (i = i1; i <= fine; i++) {
		getPointer(first_elem, i)->value = get(second_elem, i);
	}
}

void mergeSortInner(root first_elem, int first, int last, root second_elem)
{
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSortInner(first_elem, first, mid, second_elem);
		mergeSortInner(first_elem, mid + 1, last, second_elem);
		merge(first_elem, first, mid + 1, last, second_elem);
	}
}

void quickSortInner(root first_elem, int iniz, int fine)
{
	int i, j, iPivot;
	myType pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = get(first_elem, iPivot);
		do { /* trova la posizione del pivot */
			while (i < j && (compare(get(first_elem, i), pivot) == 1 || compare(get(first_elem, i), pivot) == 0)) i++;
			while (j > i && (compare(get(first_elem, j), pivot) == -1 || compare(get(first_elem, j), pivot) == 0)) j--;
			if (i < j) swapElem(first_elem, i, j);
		} while (i < j);
		if (i != iPivot && compare(get(first_elem, i), get(first_elem, iPivot)) != 0)
		{
			swapElem(first_elem, i, iPivot);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortInner(first_elem, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortInner(first_elem, iPivot + 1, fine);
	}
}

void naiveSort(root first_elem)
{
	int p;
	int size = lenght(first_elem);
	while (size > 1) {
		p = trovaPosMax(first_elem, size);
		if (p < size - 1) {
			swapElem(first_elem, p, size - 1);
		}
		size--;
	}
}

void bubbleSort(root first_elem)
{
	int i, ordinato = 0;
	int size = lenght(first_elem);
	while (size > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < size - 1; i++)
			if (compare(get(first_elem, i), get(first_elem, i+1)) == -1) {
				swapElem(first_elem, i, i + 1);
				ordinato = 0;
			}
		size--;
	}
}

void insertSort(root first_elem)
{
	int size = lenght(first_elem);
	int k;
	for (k = 1; k < size; k++)
		insOrd(first_elem, k);
}

void mergeSort(root* first_elem) {
	root second_elem = newCopy(*first_elem);
	mergeSortInner(*first_elem, 0, lenght(*first_elem)-1, second_elem);
	destroy(first_elem);
	*first_elem = second_elem;
}

void quickSort(root first_elem)
{
	quickSortInner(first_elem, 0, lenght(first_elem) - 1);
}
