#ifndef GRAPHIQUEGAME_H
#define GRAPHIQUEGAME_H

#include "menu.h"
#include "aisys.h"


void jeu(SDL_Surface* ecran);
void evenementjeu(SDL_Surface* ecran);
void imgload(int i, int j,SDL_Surface* ecran);
void makemoveplayerai(SDL_Surface* ecran);
int emptyPlace(int j,int Table[6][7]);
void initialisation();
void imgloadgeneral(SDL_Surface* ecran);
int isWin(int i, int j, int pt,int Table[6][7]);
void isWinplayer(int i,int j, int pt,int Table[6][7]);
int countHorizontal(int i, int j, int pt,int Table[6][7]);
int countVertical(int i, int j, int pt,int Table[6][7]);
int countDiagonal1(int i, int j, int pt,int Table[6][7]);
int countDiagonal2(int i, int j, int pt,int Table[6][7]);
void copyBoard(int tab[6][7]);
void winlose(SDL_Surface* ecran);
void evenementwinlose(SDL_Surface* ecran);
int tablefull();
void equality(SDL_Surface* ecran);


#endif // GRAPHIQUEGAME_H
