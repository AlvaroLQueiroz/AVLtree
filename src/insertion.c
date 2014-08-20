#include "insertion.h"
#include "structure.h"
#include "rotation.h"
#include <stdio.h>

void insertNo(NO **tree, NO *node, unsigned short *h){
	if(*tree == NULL){
		*tree = node;
		*h = 1;
	}
	else{
		if(node->chave < (*tree)->chave){
			insertNo(&(*tree)->esq, node, h);
			
			if(*h){
				switch((*tree)->bal){
					case 1:
						(*tree)->bal = 0;
						*h = 0;
					break;
					case 0:
						(*tree)->bal = -1;
					break;
					case -1:
						turnRight(tree, h);
					break;
				}
			}
		}
		else{
			insertNo(&(*tree)->dir, node, h);
			
			if(*h){
				switch((*tree)->bal){
					case -1:
						(*tree)->bal = 0;
						*h = 0;
					break;
					case 0:
						(*tree)->bal = 1;
					break;
					case 1:
						turnLeft(tree, h);
					break;
				}
			}
		}
	}
}
