#pragma once
#include "Mytype.h"
#include <stdlib.h>
#include <stdio.h>

//L'implementazione delle seguenti funzioni dipende fortemente da come è definito myType effettivamente e dallo scopo per cui deve essere usato

void printMytype(myType target)
{
	printf("Field1: %d\n", target.field1);
}

/*/
int compare(myType a, myType b)
{
	return NULL;
}
*/

int equals(myType a, myType b)
{
	if (a.field1 == b.field1) {
		return 1;
	}
	else {
		return 0;
	}
}
/**
myType sum(myType a, myType b)
{
	return;
}

myType subtract(myType a, myType b)
{
	return;
}

myType multiply(myType a, myType b)
{
	return;
}

myType divide(myType a, myType b)
{
	return;
}
*/
