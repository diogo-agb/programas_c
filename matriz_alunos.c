#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

#define LINHA 10
#define COLUNA 4

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	float notas[LINHA][COLUNA]={}, media, bonus, ponto_bonus;
	int i, j, add_bonus, encontrado = 0, ra_escolhido;
	char x;
	
	system("cls");
	srand(time(NULL));
	
	printf("Quantos pontos bônus para os alunos? ");
	scanf("%f", &bonus);
	
	system("cls");
	
	printf("Informe a media de aprovação dos alunos: ");
	scanf("%f", &media);
	
	printf("\nCOD\tRA\tAV1\tAV2\tMEDIA\tSTATUS\n");
	
	for(i=0; i<LINHA; i++){
		printf("%02d\t", i+1);
		
		for(j=0; j<COLUNA; j++){
			//RA
			if (j==0){
				notas[i][j] = 210000 + rand() % 10000;
			}	
			
			//AV1
			if(j==1){
				notas[i][j] = (rand() % 11) + bonus;
			}
			
			if(notas[i][1] > 10.0){
				notas[i][j] = 10.0;
			}
			
			//AV2
			if(j==2){
				notas[i][j] = (rand() % 11);
			}
			
			//MEDIA
			if(j==3){
				notas[i][j] = (notas[i][1] + notas[i][2]) / 2.0;
			}
			
			if(j==0){
				printf("%4.0f\t", notas[i][j]);		
			}else{
				printf("%4.1f\t", notas[i][j]);		
			}
			
			//STATUS
			if(j==3){
				if(notas[i][3] >= media){
					printf("Aprovado");
				}else{
					printf("Reprovado");
				}
			}
			
		}
		
		printf("\n");		
	
	}
	
	
	
	printf("\nDeseja adicionar um bonus na AV1 para um aluno específico? \n NÃO (0)\t SIM (1): ");
	scanf("%d", &add_bonus);
	
	if(add_bonus){
		
		printf("Informe o RA do aluno: ");
		scanf("%d", &ra_escolhido);
		
		for(i=0; i<LINHA; i++){
			if(notas[i][0] == ra_escolhido){
				printf("Nota atual (AV1): %.1f\n", notas[i][1]);
				printf("informe a nota bônus: ");
				scanf("%f", &ponto_bonus);
				notas[i][1] += ponto_bonus;
				
				if(notas[i][1] > 10.0){
					notas[i][1] = 10.0;
				}
				
				printf("\nNota adicionada.\n");
				printf("Nota atualizada AV1 para o RA %d: %.1f", ra_escolhido, notas[i][1]);
				encontrado = 1;	
				break;			
				
			}
		}
				
	}	
	
	printf("\nPressione Enter para atualizar a tabela...");
	x = getch();
	
	system("cls");
	
	printf("\nCOD\tRA\tAV1\tAV2\tMEDIA\tSTATUS\n");
	
	for(i=0; i<LINHA; i++){
		printf("%02d\t", i+1);
		
		for(j=0; j<COLUNA; j++){			
			//NOVA MEDIA
			if(j==3){
				notas[i][3] = (notas[i][1] + notas[i][2]) / 2.0;
			}
			
			//COLORIR
			if(notas[i][0] == ra_escolhido){
				printf("\033[5;33;40m");
			}
			
			//EXIBIR
			if(j==0){
				printf("%4.0f\t", notas[i][j]);		
			}else{
				printf("%4.1f\t", notas[i][j]);		
			}
			
			//STATUS
			if(j==3){
				if(notas[i][3] >= media){
					printf("Aprovado");
				}else{
					printf("Reprovado");
				}
			}
			
			//VOLTA COR ORIGINAL
			if(notas[i][0] == ra_escolhido){
				printf("\033[0m");
			}			
			
		}
		
		printf("\n");		
	
	}
	
	
	
	return 0;
}
