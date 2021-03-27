#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

#define LINHA 10
#define COLUNA 4

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int a, b, c;
	
	printf("Informe três números: ");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	printf("Números digitados nesta ordem %d e %d e %d.\n\n", a, b, c);
	
	printf("Números organizados em ordem decrescente: \n");
	
	if(a>=c && b>=c){
		printf("%d, %d, %d", a, b, c);
	}else if(a>=c && c>=b){
		printf("%d, %d, %d", a, c, b);
	}else if(b>=a && a>=c){
		printf("%d, %d, %d", b, a, c);
	}else if(b>=c && c>=a){
		printf("%d, %d, %d", b, c, a);
	}else if(c>=a && a>=b){
		printf("%d, %d, %d", c, a, b);
	}else {
		printf("%d, %d, %d", c, b, a);
	}	
	
	return 0;
}
