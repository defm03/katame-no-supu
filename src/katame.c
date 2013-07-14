#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

struct screeninfo{
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;
	int SCREEN_BPP = 32;
}

int main(int argc, char* args[]){
	 
	printf("Initializing SDL...\n");
	if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)){
		printf("Could not initialize SDL %s.\n", SDL_GetError());
		exit(-1);
	}
	printf("SDL initialized.\n");

	SDL_Surface* test = NULL;
	SDL_Surface* screen = NULL;
	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	test = SDL_LoadBMP("test.bmp");

	SDL_BlitSurface(test, NULL, screen, NULL);

	SDL_Flip(screen);
	SDL_Delay(2000);

	SDL_FreeSurface(test);
	SDL_Quit();
	
	return 0;

}
