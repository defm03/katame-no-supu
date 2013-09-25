#include "audio.h"

void audio_Init_Mixer() {	
	int mixflags = MIX_INIT_OGG|MIX_INIT_MOD;
	int mixinit=Mix_Init(mixflags); /* initialization for sdl_mixer */
	if(mixinit&&mixflags != mixflags){
		printf("Mix_Init: Failed to init required ogg and mod support!\n");
		printf("Mix_Init: %s\n", Mix_GetError());
	} /* error handling */
}