#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "aisys.h"
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

int PLUSINFINITY=512;
int MINUSINFINITY=-512;
int finalDepth1=6;
int nbreNoeuds1=0;


int alpha_beta(int state[6][7], int currentDepth, bool isMax, int i, int j, int alpha, int beta)
{

	if (isWin(i, j, 2,state)==1 && !isMax)
		return PLUSINFINITY * (finalDepth1 - currentDepth + 1);


	else if (isWin(i, j, 1,state)==1 && isMax)
		return MINUSINFINITY * (finalDepth1 - currentDepth + 1);


    else if (currentDepth == finalDepth1)
		return heuristic(1,state);


    int save[6][7];
    int scores[7];
    for (int i=0;i<6;i++)for(int j=0;j<7;j++) save[i][j]=state[i][j];
    for(int j=0;j<7;j++) scores[j]=-9999;
    if (isMax)
        {
            int bestValue = -10000000; // MOINS INFINI
            vector <int> fils;
            for (int C=0; C<7; C++)
            {
                int L = emptyPlace(C,state);
                if (L!=-1)
                {
                    state[L][C]= 2;
                    int value = alpha_beta(state,currentDepth+1,0,L,C,alpha,beta);
                    fils.push_back(value);
                    nbreNoeuds1++;
                    state[L][C] = save[L][C];
                    scores[C]=value;

                    bestValue = max( bestValue, value);
                    alpha = max( alpha, bestValue);
                    if (beta<alpha)
                        break;

                }
            }

            for(int j=0;j<7;j++)
                if ( scores[j]==  *max_element(fils.begin(), fils.end()))
                {
                    if (currentDepth==0) return j;
                    else return scores[j];
                }
        }

    else if (!isMax)
        {
            int bestValue = +10000000; // PLUS INFINI
            vector <int> fils;
            for (int C=0; C<7; C++)
            {
                int L = emptyPlace(C,state);
                if (L!=-1)
                {
                    state[L][C]= 1;
                    int value = alpha_beta(state,currentDepth+1,1,L,C,alpha,beta);
                    fils.push_back(value);
                    nbreNoeuds1++;
                    state[L][C] = save[L][C];
                    scores[C]=value;

                    bestValue = min( bestValue, value);
                    beta = min( beta, bestValue);
                    if (beta<alpha)
                        break;

                }
            }

            for(int j=0;j<7;j++)
                if ( scores[j]==  *min_element(fils.begin(), fils.end()) )
                {
                    if (currentDepth==0) return j;
                    else return scores[j];
                }
        }
}



void evalH(int i, int j, int score, int pt,int Table[6][7])
{
    int p1t=pt%2+1, p2t=p1t%2+1;
    int cp1=0,cp2=0;
    for(int k=0;k<4;k++)
    {
        if(Table[i][j+k]==p2t) cp2++;
        if(Table[i][j+k]==p1t) cp1++;
    }
    editScore(score,cp1,cp2);
}

void evalV(int i, int j, int score, int pt,int Table[6][7])
{
    int p1t=pt%2+1, p2t=p1t%2+1;
    int cp1=0,cp2=0;
    for(int k=0;k<4;k++)
    {
        if(Table[i+k][j]==p2t) cp2++;
        if(Table[i+k][j]==p1t) cp1++;
    }
    editScore(score,cp1,cp2);
}

void evalD1(int i, int j, int score, int pt,int Table[6][7])
{
    int p1t=pt%2+1, p2t=p1t%2+1;
    int cp1=0,cp2=0;
    for(int k=0;k<4;k++)
    {
        if(Table[i+k][j+k]==p2t) cp2++;
        if(Table[i+k][j+k]==p1t) cp1++;
    }
    editScore(score,cp1,cp2);
}

void evalD2(int i, int j, int score, int pt,int Table[6][7])
{
    int p1t=pt%2+1, p2t=p1t%2+1;
    int cp1=0,cp2=0;
    for(int k=0;k<4;k++)
    {
        if(Table[i-k][j+k]==p2t) cp2++;
        if(Table[i-k][j+k]==p1t) cp1++;
    }
    editScore(score,cp1,cp2);
}


void editScore(int score, int cp1, int cp2)
{
    if(cp2==0)
    {
        switch(cp1)
        {
        case 1:
            score+=1;
            break;
        case 2:
            score+=10;
            break;
        case 3:
            score+=50;
        }
    }
    if(cp1==0)
    {
        switch(cp2)
        {
        case 1:
            score-=1;
            break;
        case 2:
            score-=10;
            break;
        case 3:
            score-=50;
        }
    }
}


int heuristic(int pt,int Table[6][7])
{
    int score=0;
    for(int i=0; i<6;i++)
        for(int j=0; j<4;j++)
        {
            evalH(i,j, score, pt,Table);
        }
    for(int i=0; i<3;i++)
        for(int j=0; j<7;j++)
        {
            evalV(i,j, score, pt,Table);
        }
    for(int i=0; i<3;i++)
        for(int j=0; j<4;j++)
        {
            evalD1(i,j, score, pt,Table);
        }
    for(int i=3; i<6;i++)
        for(int j=0; j<4;j++)
        {
            evalD2(i,j, score, pt,Table);
        }

    return score;
}
