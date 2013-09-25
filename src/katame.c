/**
 * @author: Kamil Żak - defm03 (defm03@outlook.jp)
 * release: 25-09-2013
 */

#include "katame.h"

extern int gfx_Init_SDL(void);
extern void gfx_Init_Image(void);
extern void gfx_Init_Screen(void);
extern void gfx_image_Draw(char);
extern void audio_Init_Mixer(void);

int main(int argc, char* args[]){

	printf("Initializing SDL...\n");
	if (gfx_Init_SDL() == 0) { printf("SDL initialized.\n"); }
	else { printf("Error initializing, ending."); exit(0); } // error handler 
	
	gfx_Init_Image();
	audio_Init_Mixer();

	/* SDL_Surface variables */
	SDL_Surface* screen = NULL;
	SDL_Surface* image	= NULL;
	
	/* Image load */
	char image_one[] = "sample.png";
	char image_two[] = "yesand.png";

	gfx_Init_Screen();

	image_Draw(image_two);
	image_Draw(image_one);

	audio_Init_Mixer();

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
