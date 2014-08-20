#include "destroy.h"
#include <stdlib.h>

void destroy(NO **tree){
	if(tree){
		if((*tree)->esq){
			destroy(&(*tree)->esq);
		}
		if((*tree)->dir){
			destroy(&(*tree)->dir);
		}
	}
	free(*tree);
}
