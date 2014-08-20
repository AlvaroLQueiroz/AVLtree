#include "store.h"
#include "structure.h"
#include "insertion.h"
#include <stdio.h>
#include <stdlib.h>

void record(NO *tree){
	FILE *bd;
	char nameFile[255];
	
	bd = NULL;
	
	printf("Informe o nome do arquivo para gravacao da arvore: ");
	scanf("%s", nameFile);
	bd = fopen(nameFile, "wb");

	if(!bd){
		printf("Erro ao criar o arquivo.\n");
	}
	else{
		fileRecord(tree, bd);
		fclose(bd);
	}
}

void fileRecord(NO *node, FILE *bd){
	int key;

	if(node){
		fileRecord(node->esq, bd);
		key = node->chave;
		printf("%d\n", key);
		fwrite(&key, sizeof(int), 1, bd);
		fileRecord(node->dir, bd);
	}
}

void recover(NO **tree, char *nameFile){
	FILE *bd;
	NO *node;
	int key;
	unsigned short balance;

	if(!nameFile){
		printf("Informeo nome do arquivo para a leitura da arvore: ");
		nameFile = (char*) malloc(sizeof(char) * 255);
		if(!nameFile){
			printf("Erro ao alocar memoria para ler o nome do arquivo.\n");
		}
		else{
			scanf("%s", nameFile);
		}
	}

	bd = fopen(nameFile, "rb");
	if(!bd){
		printf("Erro ao abrir o arquivo.\n");
	}
	else{
		while(fread(&key, sizeof(int), 1, bd)){
			node = (NO*) malloc(sizeof(NO));
			if(!node){
				printf("Erro ao alocar um nó.\n");
			}
			else{
				node->chave = key;
				node->bal = 0;
				node->esq = NULL;
				node->dir= NULL;
				insertNo(tree, node, &balance);
				node = NULL;
			}
		}
		fclose(bd);
	}
}
