#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>


int sorteio[5] = {9, 30, 75, 3, 42};

void exibirVetor(int v[], int n){
	int i;
	for(i=0; i<5; i++){
		printf("%2d  ", v[i]);
	}
	printf("\n");
}

void ordenarBolha(int v[], int n){
	
	int i, j, temp;
	
	for(i=0; i<n; i++){
		printf("\n-----------\n");
		for(j=0; j<(n-1)-i; j++){
			printf("%2d > %2d", v[j], v[j+1]);
			if(v[j] > v[j+1]){
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
				printf("\t\t(Troca) \t");
				exibirVetor(v, 5);
			}else{
				printf("\t\t(Manter)\t");
				exibirVetor(v, 5);
			}
		}
	}
	
}

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));	
	
	int i;		
	
	printf("Antes da ordenação:\n");
	for(i=0; i<5; i++){
		printf("%d ", sorteio[i]);
	}
	
	printf("\n\nExibir as trocas da oedenação:\n");
	ordenarBolha(sorteio, 5);	
	
	printf("\n\nDepois da ordenação:\n");	
	
	for(i=0; i<5; i++){
		printf("%d ", sorteio[i]);
	}
	
	
	return 0;
}
