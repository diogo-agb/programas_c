#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

#define I 5 // Linha
#define J 20 // Coluna

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	
	int sorteios[I][J]={};
	int v_temp[6]={};
	int l, c, i;
	
	for(l=0; l<I; l++){
		
		for(c=0; c<J; c++){	
			sorteios[l][c] = 1 + rand() % 60;
			v_temp[c] = sorteios[l][c];	
		}	
		
		for(i=0; i<J; i++){
			if(v_temp[i] == sorteios[l][c]){
				--c;
				--l;
				break;							
			}
		}	
	}
	

	
	
	
	for(l=0; l<I; l++){
		for(c=0; c<J; c++){
			printf("%.2d ", sorteios[l][c]);
		}
		printf("\n");
	}
	
	return 0;
}
