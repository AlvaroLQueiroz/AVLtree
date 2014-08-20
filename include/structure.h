#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

typedef struct s_no
{
	int chave:28;
	int bal:4;
	struct s_no* esq;
	struct s_no* dir;
}NO;

#endif
