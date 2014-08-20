#include "read.h"
#include "structure.h"
#include "insertion.h"
#include <stdio.h>
#include <stdlib.h>

void readNode(NO **tree){
	NO *newNode;
	unsigned short h;
	int chave;
	
	newNode = (NO*) malloc(sizeof(NO));
	if(!newNode){
		printf("Erro ao alocar memoria.\n");
	}
	else{
		printf("Informe o valor da chave: ");
		scanf(" %d", &chave);
		newNode->chave = chave;
		newNode->bal = 0;
		newNode->esq = NULL;
		newNode->dir = NULL;
		h = 0;
		insertNo(tree, newNode, &h); 
	}
}
