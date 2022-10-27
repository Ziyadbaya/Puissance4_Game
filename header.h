#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <SDL_image.h>

void evenementboard(SDL_Surface* ecran);
void game(SDL_Surface* ecran);
void evenement(SDL_Surface* ecran);
void menu(SDL_Surface* ecran);
void rules(SDL_Surface* ecran);
void evenementrules(SDL_Surface* ecran);
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
int alpha_beta(int state[6][7], int currentDepth, int isMax, int i, int j, int alpha, int beta);
void evalH(int i, int j, int score, int pt,int Table[6][7]);
void evalV(int i, int j, int score, int pt,int Table[6][7]);
void evalD1(int i, int j, int score, int pt,int Table[6][7]);
void evalD2(int i, int j, int score, int pt,int Table[6][7]);
void editScore(int score, int cp1, int cp2);
int heuristic(int pt,int Table[6][7]);


#endif // HEADER_H_INCLUDED
