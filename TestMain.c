/**
* File usato per generare e testare tutte le funzioi in modo automatizzato
*/
#include <stdio.h>
#include "Misclib.h"
#include <stdlib.h>

int main() {
	FILE* in;
	fopen_s(&in, "testCases.txt", "r");
	
	if (in == NULL) {
		printf("\aC'e' stato un problema in fase di apertura di un file!\n");
	}

	int param1, param2, param3;
	int out1, out2, out3;
	int outFun1, outFun2, outFun3;
	int line = 0;
	int wrong = 0;

	while (fscanf_s(in, "%d %d", &param1, &out1) != EOF) {
		line++;
		if (out1 != (outFun1 = invertiNum(param1))) {
			printf("\aTestcase %d sbagliato! Param1: %d		Res1: %d\n", line, param1, outFun1);
			wrong++;
		}
		else {
			printf("Testcase %d passato!\n", line);
		}
	}

	printf("%d / %d errori trovati.\n\n\n", wrong, line);
	fclose(in);
}
