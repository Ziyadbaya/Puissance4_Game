#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "menu.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <windows.h>


void menu(SDL_Surface* ecran)
{
    SDL_WM_SetCaption("Connect4", NULL);
    SDL_WM_SetIcon(IMG_Load("icone.ico") , NULL);
    SDL_Surface* image=NULL;
    ecran=SDL_SetVideoMode(1080,844,32,SDL_HWSURFACE);
    SDL_Rect position;
    position.x=0;position.y=0;
    image=IMG_Load("main menu.png");
    SDL_BlitSurface(image,NULL,ecran,&position);
    SDL_Flip(ecran);

    evenement(ecran);
    Mix_CloseAudio();
    SDL_FreeSurface(image);
}

void evenement(SDL_Surface* ecran)
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
                if (event.button.x>367.00 && event.button.x<700 && event.button.y>456.00 && event.button.y<548)
                {
                    Beep(20,30);
                    game(ecran);
                    continuer=0;
                    break;
                }
                if (event.button.x>367.00 && event.button.x<700 && event.button.y>563.50 && event.button.y<655.5)
                {
                    Beep(20,30);
                    rules(ecran);
                    continuer=0;
                    break;
                }

                break;
        case SDL_QUIT:
                continuer = 0;

        }
    }
}
