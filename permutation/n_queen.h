#ifndef __N_QUEEN_H
#define __N_QUEEN_H

# include "per.h"
#include <iostream>

bool IsValidPossibility(SEQPTR, int n);

bool ISCheck(SEQARR,SEQARR,SEQARR,SEQARR);

void GenerateSol();

void printpos(SEQPTR,int n);

#endif
