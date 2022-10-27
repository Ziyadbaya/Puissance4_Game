#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "board.h"
#include <SDL_image.h>
#include <windows.h>
#include <SDL_mixer.h>

void game(SDL_Surface* ecran)
{
    SDL_Surface* image=NULL;
    SDL_Rect position;
    position.x=0;position.y=0;
    image=IMG_Load("second menu.png");
    SDL_BlitSurface(image,NULL,ecran,&position);
    SDL_Flip(ecran);
    evenementboard(ecran);
    SDL_FreeSurface(image);
}

void evenementboard(SDL_Surface* ecran)
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
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

                if (event.button.x>367.00 && event.button.x<700 && event.button.y>624 && event.button.y<715)
                {
                    Beep(20,30);
                    jeu(ecran);
                    continuer=0;
                    break;
                }
                if (event.button.x>367.00 && event.button.x<700 && event.button.y>730 && event.button.y<821)
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

