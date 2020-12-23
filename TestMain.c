/**
* File usato per generare e testare tutte le funzioi in modo automatizzato
*/
#define pragma once
#include <stdio.h>
#include "Misclib.h"
#include <stdlib.h>
#include "Mytype.h"
#include "Myarray.h"
#include "Mylist.h"

int main() {

	root list_root = newList();

	myType a;
	a.field1 = 10;
	myType b;
	b.field1 = 15;
	myType c;
	c.field1 = 18;
	myType d;
	d.field1 = 25;

	list_root = add(a, list_root);
	list_root = add(b, list_root);
	list_root = add(c, list_root);
	list_root = add(d, list_root);

	printf("%d", lenght(list_root));

	return 0;
}
