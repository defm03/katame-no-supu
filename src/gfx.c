#include "gfx.h"

int gfx_Init_SDL() {
	if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)){
		printf("Could not initialize SDL %s.\n", SDL_GetError());
		exit(-1);
	} // initialization of sdl
	return 0;
}

void gfx_Init_Image() {
	int imgflags = IMG_INIT_JPG | IMG_INIT_PNG;
	int imginit=IMG_Init(imgflags);	/* initialization for sdl_image */ 
	if(imginit&&imgflags != imgflags){
		printf("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	} // error handling
}

void gfx_Init_Screen() {
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
	if(!screen){
		printf("Screen initialization: %s\n", IMG_GetError());
	} // error handling 
}

void gfx_image_Draw(char name[]) {
	// name == name of file, path should handle going to 'res' directory
	char path[] = "/res/";
	char f_path[];

	strcpy(f_path, strcat(path, name));

	image = IMG_Load(f_path);
	if(!image){
		printf("IMG_Load: %s\n", IMG_GetError());
	} // error handling
}

