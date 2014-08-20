#include "remotion.h"
#include "structure.h"
#include "balance.h"
#include <stdio.h>
#include <stdlib.h>

void remotion(NO **tree){
	int key;
	unsigned short removed;

	removed = 0;
	if(*tree){
		printf("Informe a chave a ser removida: ");
		scanf("%d", &key);

		findKey(tree, key, &removed);

		if(removed){
			balance(tree);
			printf("Nó removido com sucesso.\n");
		}
		else{
			printf("Nó nao encontrado.\n");
		}
	}
	else{
		printf("A arvore esta vazia.\n");
	}
}

void findKey(NO **subTree, int key, unsigned short *removed){
	if(*subTree != NULL){
		if((*subTree)->chave == key){
			removeNode(subTree);
			*removed = 1;
		}
		else if((*subTree)->chave > key){
			findKey(&(*subTree)->esq, key, removed);
		}
		else{
			findKey(&(*subTree)->dir, key, removed);
		}
	}
}

void removeNode(NO **node){
	NO *new;
	NO *father;

	if((*node)->esq == NULL){
		*node = (*node)->dir;
	}
	else{
		new = (*node)->esq;
		father = (*node)->esq;

		while(new->dir != NULL){
			father = new;
			new = new->dir;
		}

		if(new == father){
			new->dir = (*node)->dir;
			*node = new;
		}
		else{
			father->dir = new->esq;
			new->esq = (*node)->esq;
			new->dir = (*node)->dir;
			*node = new;
		}
	}
}
