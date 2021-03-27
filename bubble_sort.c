#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

#define N 5

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	
	int valores[N] = {41, 3, 85, 39, 56};
	int i, j, temp;
	
	
	
	printf("Antes da ordenação:\n");
	for(i=0; i<N; i++){
		printf("%d ", valores[i]);
	}
	
	printf("\n\nDepois da ordenação:\n");
	
	for(i=0; i<N; i++){
		for(j=0; j<(N-1)-i; j++){
			if(valores[j] > valores[j+1]){
				temp = valores[j];
				valores[j] = valores[j+1];
				valores[j+1] = temp;
			}
		}
	}
	
	for(i=0; i<N; i++){
		printf("%d ", valores[i]);
	}
	
	
	return 0;
}
