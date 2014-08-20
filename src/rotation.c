#include "rotation.h"
#include "structure.h"
#include <stdio.h>

void turnLeft(NO **subTree, unsigned short *h){
	NO *ptu, *ptv;
	
	ptu = (*subTree)->dir;
	
	if(ptu->bal == 1){
		(*subTree)->dir = ptu->esq;
		ptu->esq = *subTree;
		(*subTree)->bal = 0;
		*subTree = ptu;
	}
	else{
		ptv = ptu->esq;
		ptu->esq = ptv->dir;
		ptv->dir = ptu;
		(*subTree)->dir = ptv->esq;
		ptv->esq = *subTree;
		
		if(ptv->bal == 1){
			(*subTree)->bal = -1;
		}
		else{
			(*subTree)->bal = 0;
		}
		
		if(ptv->bal == -1){
			ptu->bal = 1;
		}
		else{
			ptu->bal = 0;
		}
		
		*subTree = ptv;
	}
	(*subTree)->bal = 0;
	*h = 0;
}

void turnRight(NO **subTree, unsigned short *h){
	NO *ptu, *ptv;
	
	ptu = (*subTree)->esq;
	
	if(ptu->bal == -1){
		(*subTree)->esq = ptu->dir;
		ptu->dir = *subTree;
		(*subTree)->bal = 0;
		*subTree = ptu;
	}
	else{
		ptv = ptu->dir;
		ptu->dir = ptv->esq;
		ptv->esq = ptu;
		(*subTree)->esq = ptv->dir;
		ptv->dir = *subTree;
		
		if(ptv->bal == -1){
			(*subTree)->bal = 1;
		}
		else{
			(*subTree)->bal = 0;
		}
		
		if(ptv->bal == 1){
			ptu->bal = -1;
		}
		else{
			ptu->bal = 0;
		}
		
		*subTree = ptv;
	}
	
	(*subTree)->bal = 0;
	*h = 0;
}
