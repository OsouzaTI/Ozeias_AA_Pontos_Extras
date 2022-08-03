#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int 
	B, // numero de bancos
	N; // numero de debentures
	
	
	while(1) {

		scanf("%d %d", &B, &N);
		if(B == 0 && N == 0)
			break;

		int R[B]; // reservas
		int i;
		for(i = 0; i < B; i++)
			scanf("%d", &R[i]);
		// x1 -> Banco Devedor
		// x2 -> Banco Credor
		// x3 -> Valor da debenture
		int x1, x2, x3, aux;
		for(i = 0; i < N; i++) {
			scanf("%d %d %d", &x1, &x2, &x3);
			R[x1 - 1] -= x3;
			R[x2 - 1] += x3; 
		}

		aux = 0;
		for(i = 0; i < B; i++) {
			if(R[i] < 0) {
				printf("N\n");
				aux = 1;
				break;
			}
		}
		if(!aux) printf("S\n");
	}
	
	return 0;
}
