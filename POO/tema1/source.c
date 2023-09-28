#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void eliminaDubluri(int* v, int *dim) {
	int i;
	int* uniq, newdim = 0, j, ok;
	uniq = (int*)malloc(*dim * sizeof(int));
	for (i = 0; i < *dim; i++) {
		ok = 1;
		for (j = 0; j < newdim && ok == 1; j++) {
			if (v[i] == uniq[j])
				ok = 0;
		}
		if (ok == 1) {
			v[newdim] = v[i];
			uniq[newdim++] = v[i];
		}
	}

	*dim = newdim;
}
void inlocuiesteMinus1(int* v, int dim) {
	int i;
	int* sorted, j, aux, sortedDim = dim;
	sorted = (int*)malloc(dim * sizeof(int));
	for (i = 0; i < dim; i++) {
		sorted[i] = v[i];
	}
	for (i = 0; i < dim; i++) {
		for (j = i + 1; j < dim; j++) {
			if (sorted[i] > sorted[j]) {
				aux = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = aux;
			}
		}
	}
	eliminaDubluri(sorted, &sortedDim);

	for (i = 0; i < dim; i++) {
		for (j = 0; j < 3 && j < sortedDim; j++) {
			if (v[i] == sorted[j]) {
				v[i] = -1;
			}
		}
	}
}

int main() {
	int dim, *v, i;
	printf("Dimensiunea vectorului= ");
	scanf("%d", &dim);
	v = (int*)malloc(dim * sizeof(int));
	for (i = 0; i < dim; i++) {
		printf("v[%d]=", i);
		scanf("%d", &v[i]);
	}
	 /*
	eliminaDubluri(v, &dim);
	for (i = 0; i < dim; i++) {
		printf("%d ", v[i]);
	}
	*/

	
	inlocuiesteMinus1(v, dim);
	for (i = 0; i < dim; i++) {
		printf("%d ", v[i]);
	}
	

	free(v);
	return	0;
}