#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "graphiquegame.h"
#include <SDL_image.h>
#include <windows.h>
#include <SDL_mixer.h>


int T[6][7];
int turn;
int exitgame,win;

void jeu(SDL_Surface* ecran)
{
    SDL_Surface* image=NULL;
    SDL_Rect position;
    position.x=0;position.y=0;
    image=IMG_Load("game.png");
    SDL_BlitSurface(image,NULL,ecran,&position);
    SDL_Flip(ecran);
    initialisation();
    SDL_Flip(ecran);
    exitgame=0;
    while(tablefull()==0 && win==0 && exitgame==0)
    {
        evenementjeu(ecran);
        if (win==0)
        {makemoveplayerai(ecran);}
        imgloadgeneral(ecran);
        // affichage des pions
         // le tour de l'ia
    }
    SDL_FreeSurface(image);
    if (win!=0)
    {winlose(ecran);}
    if (win==0 && tablefull()==1)
    {
        equality(ecran);
    }


}

int tablefull()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            if (T[i][j]==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void evenementjeu(SDL_Surface* ecran)
{
    int i,j;
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            deb:
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.x>883 && event.button.x<1005 && event.button.y>254 && event.button.y<375)
            {
                if(Mix_PausedMusic() == 1)//Si la musique est en pause
                    {
                        Mix_ResumeMusic(); //Reprendre la musique
                    }
                    else
                    {
                        Mix_PauseMusic(); //Mettre en pause la musique
                    }
            }
            if (turn%2+1==1 && event.button.x>113 && event.button.x<184 && event.button.y>290 && event.button.y<810)
                {
                    Beep(20,30);
                    j=0; // get desired column to play from player
                    i=emptyPlace(j,T); // retuns empty line in the chosen column
                    if(i==-1) {goto deb;}
                    T[i][j]=1;
                    isWinplayer(i,j,1,T);
                    turn++;
                    continuer=0;

                }
                if (turn%2+1==1 && event.button.x>205 && event.button.x<277 && event.button.y>290 && event.button.y<810)
                {
                    Beep(20,30);
                    j=1; // get desired column to play from player
                    i=emptyPlace(j,T); // retuns empty line in the chosen column
                    if(i==-1) {goto deb;}
                    T[i][j]=1;
                    isWinplayer(i,j,1,T);
                    turn++;
                    continuer=0;
                }
                if (turn%2+1==1 && event.button.x>298 && event.button.x<369 && event.button.y>290 && event.button.y<810)
                {
                    Beep(20,30);
                    j=2; // get desired column to play from player
                    i=emptyPlace(j,T); // retuns empty line in the chosen column
                    if(i==-1) {goto deb;}
                    T[i][j]=1;
                    isWinplayer(i,j,1,T);
                    turn++;
                    continuer=0;
                }
                if (turn%2+1==1 && event.button.x>391 && event.button.x<462 && event.button.y>290 && event.button.y<810)
                {
                    Beep(20,30);
                    j=3; // get desired column to play from player
                    i=emptyPlace(j,T); // retuns empty line in the chosen column
                    if(i==-1) {goto deb;}
                    T[i][j]=1;
                    isWinplayer(i,j,1,T);
                    turn++;
                    continuer=0;
                }
                if (turn%2+1==1 && event.button.x>483 && event.button.x<555 && event.button.y>290 && event.button.y<810)
                {
                    Beep(20,30);
                    j=4; // get desired column to play from player
                    i=emptyPlace(j,T); // retuns empty line in the chosen column
                    if(i==-1) {goto deb;}
                    T[i][j]=1;
                    isWinplayer(i,j,1,T);
                    turn++;
                    continuer=0;
                }
                if (turn%2+1==1 && event.button.x>576 && event.button.x<648 && event.button.y>290 && event.button.y<810)
                {
                    Beep(20,30);
                    j=5; // get desired column to play from player
                    i=emptyPlace(j,T); // retuns empty line in the chosen column
                    if(i==-1) {goto deb;}
                    T[i][j]=1;
                    isWinplayer(i,j,1,T);
                    turn++;
                    continuer=0;
                }
                if (turn%2+1==1 && event.button.x>669 && event.button.x<740 && event.button.y>290 && event.button.y<810)
                {
                    Beep(20,30);
                    j=6; // get desired column to play from player
                    i=emptyPlace(j,T); // retuns empty line in the chosen column
                    if(i==-1) {goto deb;}
                    T[i][j]=1;
                    isWinplayer(i,j,1,T);
                    turn++;
                    continuer=0;
                }
                if (event.button.x>832 && event.button.x<1062 && event.button.y>698 && event.button.y<812)
                {
                    Beep(20,30);
                    exitgame=1;
                    menu(ecran);
                    continuer=0;
                }

            break;
        case SDL_QUIT:
                continuer = 0;
        }
    }
}



void imgloadgeneral(SDL_Surface* ecran)
{
    if(exitgame==0)
    {for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            imgload(i,j,ecran);
        }
    }}
}

void imgload(int i, int j,SDL_Surface* ecran) // pour importer les pions
{
    if(T[i][j]!=0){
    SDL_Surface* image=NULL;
    SDL_Rect position;
    position.x=113+j*92;position.y=290+i*90;
    if(T[i][j]==1){
        image=IMG_Load("player1.png");
    }
    if(T[i][j]==2){
        image=IMG_Load("player2.png");
    }
    SDL_BlitSurface(image,NULL,ecran,&position);
    SDL_Flip(ecran);
    SDL_FreeSurface(image);
    }
}

void initialisation()
{
    win=0;
    turn=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            T[i][j]=0;
        }
    }
}


void makemoveplayerai(SDL_Surface* ecran)
{
    int i,j;
    if(turn%2+1==2) //  2 if ai's turn
    {
        int state[6][7];
        copyBoard(state);
        j=alpha_beta(state,0,true,0,0,-100000000000,+100000000000);
        i=emptyPlace(j,T);
        T[i][j]=2;
        isWinplayer(i,j,2,T);
        turn++;
    }
}

void copyBoard(int tab[6][7])
{
    for (int i=0;i<6;i++)for(int j=0;j<7;j++) tab[i][j] = T[i][j];
}

int emptyPlace(int j,int Table[6][7])
{
    int i;
    if(Table[0][j]!=0) return -1; // return -1 when the column is FULL
    for(i=0;i<5;i++)
        if(Table[i+1][j]!=0) // this means when i+1 is FULL, we break and return i (i is above i+1)
            break;
    return i;
}


int isWin(int i, int j, int pt,int Table[6][7])
{
    if (Table[i][j]==pt && (countHorizontal(i,j,pt,Table)==4 || countVertical(i,j,pt,Table)==4 || countDiagonal1(i,j,pt,Table)==4 || countDiagonal2(i,j,pt,Table)==4))
    {
        return 1;
    }
    else return 0;
}

void isWinplayer(int i,int j, int pt,int Table[6][7])
{
    if(isWin(i,j,pt,Table)==1)
    {
        if (pt==1)
        {
            win=1;
        }
        if (pt==2)
        {
            win=2;
        }
    }
}

int countHorizontal(int i, int j, int pt, int Table[6][7])
{
    int u,v;
    int counter=0;
        u=i; v=j;
        while(u>=-1 && u<6 && v>-1 && v<7 && Table[u][v++]==pt && counter<4)
            counter++;
        u=i; v=j-1;
        while(u>-1 && u<6 && v>-1 && v<7 && Table[u][v--]==pt && counter<4)
            counter++;
    return counter;
}

int countVertical(int i, int j, int pt,int Table[6][7])
{
    int u,v;
    int counter=0;

    u=i; v=j;
    while(u>-1 && u<6 && v>-1 && v<7 && Table[u++][v]==pt && counter<4)
        counter++;
    u=i-1; v=j;
    while(u>-1 && u<6 && v>-1 && v<7 && Table[u--][v]==pt && counter<4)
        counter++;
    return counter;
}

int countDiagonal1(int i, int j, int pt,int Table[6][7])
{
    int u,v;
    int counter=0;

    u=i; v=j;
    while(u>-1 && u<6 && v>-1 && v<7 && Table[u++][v++]==pt && counter<4)
        counter++;
    u=i-1; v=j-1;
    while(u>-1 && u<6 && v>-1 && v<7 && Table[u--][v--]==pt && counter<4)
        counter++;

    return counter;
}

int countDiagonal2(int i, int j, int pt,int Table[6][7])
{
    int u,v;
    int counter=0; // on suppose que Table[i][j]==pt

    u=i; v=j;
    while(u>-1 && u<6 && v>-1 && v<7 && Table[u++][v--]==pt && counter<4)
        counter++;
    u=i-1; v=j+1;

    while(u>-1 && u<6 && v>-1 && v<7 && Table[u--][v++]==pt && counter<4)
        counter++;

    return counter;
}

void winlose(SDL_Surface* ecran) //3764 280
{
    SDL_Surface* image=NULL;
    SDL_Rect position;
    position.x=0;position.y=0;
    if (win==1)
    {
        image=IMG_Load("win.png");
    }
    if (win==2)
    {
        image=IMG_Load("lose.png");
    }
    SDL_BlitSurface(image,NULL,ecran,&position);
    SDL_Flip(ecran);
    evenementwinlose(ecran);
    SDL_FreeSurface(image);
}

void equality(SDL_Surface* ecran) //3764 280
{
    SDL_Surface* image=NULL;
    SDL_Rect position;
    position.x=0;position.y=0;
    image=IMG_Load("equa.png");
    SDL_BlitSurface(image,NULL,ecran,&position);
    SDL_Flip(ecran);
    evenementwinlose(ecran);
    SDL_FreeSurface(image);
}

void evenementwinlose(SDL_Surface* ecran)
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_MOUSEBUTTONDOWN:

                if (event.button.x>738 && event.button.x<1069 && event.button.y>21 && event.button.y<114)
                {
                    Beep(20,30);
                    menu(ecran);
                    continuer=0;
                    break;
                }

            break;
        case SDL_QUIT:
                continuer = 0;
        }
    }
}



