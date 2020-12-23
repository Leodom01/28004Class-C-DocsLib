/**
*
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
	}else {
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
	toAdd = (item*) malloc(sizeof(item));
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
	while (pointer->next != NULL) {
		printMytype(pointer->value);
		pointer = pointer->next;
	}
	printMytype(pointer->value);
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
	while (pointer->next != NULL){
		if (equals(pointer->value, elem)) {
			return index;
		}
		pointer = pointer->next;
		index++;
	}
	return -1;
}

int lenght(root first_elem)
{
	int lenght = 0;
	if (first_elem == NULL) {
		return lenght;
	}
	lenght ++;
	item* pointer = first_elem;
	while (pointer->next != NULL) {
		lenght++;
		pointer = pointer->next;
	}
	return lenght;
}

//TODO Ho testato tutte le funzioni solo fino a qui
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

	root newRoot = (item*) malloc(sizeof(item));
	if (newRoot == NULL) {
		exit(-5);
	}
	newRoot->value = first_elem->value;
	newRoot->next = NULL;
	item* newPointer = newRoot;
	item* pointer = first_elem;
	while (pointer->next != NULL) {
		pointer = pointer->next;
		newPointer->next = (item*) malloc(sizeof(item));
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
		swapElem(first_elem, i, lenght(first_elem) - i);
	}
}

void destroy(root first_elem)
{
	item* pointer = first_elem;

	if (first_elem == NULL) {
		return;
	}
	while (

		pointer->next != NULL) {
		item* toKill = pointer;
		pointer = pointer->next;
		free(toKill);
	}
	free(pointer);
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

void deleteOcc(root first_elem, myType elem)
{
	int indexToKill = find(elem, first_elem);
	item* preTarget = getPointer(first_elem, indexToKill - 1);
	item* postTarget= getPointer(first_elem, indexToKill + 1);
	preTarget->next = postTarget;
	item* target = getPointer(first_elem, indexToKill);
	free(target);
}

root subList(root first_elem, int start_index, int end_index)
{
	int len = lenght(first_elem);
	if (first_elem == NULL) {
		return NULL;
	}
	if (start_index < 0 || end_index < 0 || start_index >= len || end_index >= len) {
		return NULL;
	}

	root newRoot = (item*) malloc(sizeof(item));
	int index = start_index;
	item* pointer = newRoot;
	while (index < end_index) {
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
		return 0;
	}
	int len = lenght(first_elem);
	if (arr_size < len) {
		return 0;
	}
	for (int i = 0; i < len; i++) {
		arr[i] = get(first_elem, i);
	}
	return 1;
}

void addAt(root* first_elem, myType elem, int index)
{
	if (first_elem == NULL || index > lenght(*first_elem)) {
		exit(-7);
	}else if (index == 0) {
		*first_elem = add(elem, *first_elem);
		return;
	}else if (index == lenght(*first_elem)) {
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
	}else if (index >= len) {
		return -1;
	}else if (index == 0) {
		item* toDel = *first_elem;
		*first_elem = getPointer(*first_elem, 1);
		free(toDel);
		return 1;
	}else if (index + 1 == len) {
		item* preToDel = getPointer(*first_elem, len - 2);
		item* toDel = preToDel->next;
		preToDel->next = NULL;
		free(toDel);
		return 1;
	}
	else {
		item* preToDel = getPointer(*first_elem, index);
		item* toDel = preToDel->next;
		item* postToDel = toDel->next;
		preToDel->next = postToDel;
		free(toDel);
		return 1;
	}

}

/**
void naiveSort(root first_elem)
{
}

void bubbleSort(root first_elem)
{
}

void insertSort(root first_elem)
{
}

void mergeSort(root first_elem)
{
}

void quickSort(root first_elem)
{
}

*/
