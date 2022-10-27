#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "menu.h"
#include <SDL_image.h>
#include <SDL_mixer.h>



int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface* ecran=NULL;
    int continuer=1;
    SDL_Event event;
     if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
   Mix_Music *musique; //Création du pointeur de type Mix_Music
   musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
   Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
   menu(ecran);
   while(continuer)
   {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
         case SDL_QUIT:
            continuer = 0;
            break;
      }
   }
   Mix_FreeMusic(musique);
    Mix_CloseAudio();
    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).

}
