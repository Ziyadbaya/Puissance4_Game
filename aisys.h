#ifndef AISYS_H
#define AISYS_H

#include "graphiquegame.h"


int alpha_beta(int state[6][7], int currentDepth, bool isMax, int i, int j, int alpha, int beta);
void evalH(int i, int j, int score, int pt,int Table[6][7]);
void evalV(int i, int j, int score, int pt,int Table[6][7]);
void evalD1(int i, int j, int score, int pt,int Table[6][7]);
void evalD2(int i, int j, int score, int pt,int Table[6][7]);
void editScore(int score, int cp1, int cp2);
int heuristic(int pt,int Table[6][7]);

#endif // AISYS_H
