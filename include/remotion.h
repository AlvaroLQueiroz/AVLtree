#ifndef _REMOTION_H_
#define _REMOTION_H_

#include "structure.h"

void remotion(NO **tree);

void findKey(NO **subTree, int key,  unsigned short *removed);

void removeNode(NO **node);

#endif
