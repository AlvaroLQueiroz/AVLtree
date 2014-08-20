#include "balance.h"
#include "structure.h"
#include "rotation.h"

int calculateBalance(NO **subTree, short *continua){
	int he, hd;
	unsigned short h;

	if(!*subTree){
		return -1;
	}
	else{
		he = calculateBalance(&(*subTree)->esq, continua);
		hd = calculateBalance(&(*subTree)->dir, continua);
		(*subTree)->bal = hd - he;

		if((*subTree)->bal == 2){
			turnLeft(subTree, &h);
			*continua = 1;
		}
		else if((*subTree)->bal == -2){
			turnRight(subTree, &h);
			*continua = 1;
		}

		if(he < hd){
			return hd + 1;
		}
		else{
			return he + 1;
		}
	}
}

void balance(NO **subTree){
	short continua;
	continua = 1;

	while(continua){
		continua = 0;
		calculateBalance(subTree, &continua);
	}
}