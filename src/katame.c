#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

int main(int argc, char* args[]){
	 
	printf("Initializing SDL...\n");
	if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)){
		printf("Could not initialize SDL %s.\n", SDL_GetError());
		exit(-1);
	} /* initialization of sdl */
	printf("SDL initialized.\n");
	
	int imgflags = IMG_INIT_JPG | IMG_INIT_PNG;
	int imginit=IMG_Init(imgflags);	/* initialization for sdl_image */ 
	if(imginit&&imgflags != imgflags){
		printf("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	} /* error handling */

	int mixflags = MIX_INIT_OGG|MIX_INIT_MOD;
	int mixinit=Mix_Init(mixflags); /* initialization for sdl_mixer */
	if(mixinit&&mixflags != mixflags){
		printf("Mix_Init: Failed to init required ogg and mod support!\n");
		printf("Mix_Init: %s\n", Mix_GetError());
	} /* error handling */

	/* SDL_Surface variables */
	SDL_Surface* screen = NULL;
	SDL_Surface* image	= NULL;
	

	image = IMG_Load("sample.png");
	if(!image){
		printf("IMG_Load: %s\n", IMG_GetError());
	} /* error handling */

	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	if(!screen){
		printf("Screen initialization: %s\n", IMG_GetError());
	} /* error handling */


	while(SDL_BlitSurface(image, NULL, screen, NULL) == -2){
		while(SDL_LockSurface(image) < 0){SDL_Delay(10);}
		SDL_UnlockSurface(image);
	}

	/*SDL_Flip(screen);*/
	SDL_Delay(2000);
	
	IMG_Quit();
	SDL_Quit();
	
	return 0;

}
