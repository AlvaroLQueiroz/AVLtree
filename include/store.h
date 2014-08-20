#ifndef _STORE_H_
#define _STORE_H_

#include "structure.h"
#include <stdio.h>

void record(NO *tree);

void fileRecord(NO *node, FILE *bd);

void recover(NO **tree, char *nameFile);

#endif
