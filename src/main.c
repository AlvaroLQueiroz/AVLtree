#include "structure.h"
#include "read.h"
#include "gfx.h"
#include "print.h"
#include "destroy.h"
#include "store.h"
#include "remotion.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	NO *tree;
	unsigned width, height;
	int quit; /*Verifica se o programa deve ser encerrado*/
	char option;
	
	tree = NULL;
	width = 1024;
	height = 768;
	quit = 0;

	gfx_init(width, height, "AVL TREE");

	if(argc == 2){
		recover(&tree, argv[1]);
		print(tree, width / 2, 0, width / 2, 0);
		gfx_paint();
	}

	while(!quit){
		printf("Menu\nI - Insert\nR - Remove\nS - Save\nP - Import\nQ - Exit\n\n");
		printf("Informe a opcao: ");
		scanf(" %c", &option);
		option = tolower(option);
		
		switch (option){
			case 'i':
				readNode(&tree);
			break;

			case 'r':
				remotion(&tree);
			break;
			
			case 's':
				record(tree);
			break;

			case 'p':
				recover(&tree, NULL);
			break;

			case 'q':
				quit = 1;
				break;
			
			default:
				break;
		}
		gfx_clear();
		print(tree, width / 2, 0, width / 2, 0);
		gfx_paint();
		system("clear");
	}

	destroy(&tree);
	gfx_quit();
	return 0;
}
