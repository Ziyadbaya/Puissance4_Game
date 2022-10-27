#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "header.h"
#include <SDL_image.h>
#include <windows.h>

void rules(SDL_Surface* ecran)
{
    SDL_Surface* image=NULL;
    SDL_Rect position;
    position.x=0;position.y=0;
    image=IMG_Load("rules.png");
    SDL_BlitSurface(image,NULL,ecran,&position);
    SDL_Flip(ecran);
    evenementrules(ecran);
    SDL_FreeSurface(image);
}

void evenementrules(SDL_Surface* ecran)
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.x>896 && event.button.x<1005 && event.button.y>288 && event.button.y<397)
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

