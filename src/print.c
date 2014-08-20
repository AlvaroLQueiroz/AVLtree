#include "print.h"
#include "gfx.h"
#include <stdio.h>
#include <stdlib.h>

void triangle(char *text, unsigned w, unsigned h, unsigned size){
	
	gfx_line(w, h, (int) (w - size / 2), h + size);
	gfx_line(w, h, (int) (w + size / 2), h + size);
	gfx_line((int)w - size / 2, h + size, (int) (w + size / 2), h + size);
	
	gfx_text((int) (w - size * 0.2 ), h + size - gfx_get_font_size(), text);
}

void print(NO *tree, unsigned x, unsigned y, unsigned middle, short side){
	unsigned nodeSize;
	char buffer[5];

	nodeSize = 25;
	
	if(tree){
		snprintf (buffer, 5, "%d", tree->chave);
		triangle(buffer, x, y, nodeSize);
		if(y){
			gfx_line(x, y, x + side * (middle - nodeSize / 2), y - nodeSize);
		}

		print(tree->esq, x - middle / 2, y + 2 * nodeSize, middle / 2, 1);
		print(tree->dir, x + middle / 2, y + 2 * nodeSize, middle / 2, -1);
	}
}
