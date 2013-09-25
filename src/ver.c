#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

int SDL_imgver(){
	SDL_version compile_version;
	auto const SDL_version *link_version=IMG_Linked_Version();
	SDL_IMAGE_VERSION(&compile_version);

	printf("compiled with SDL_image version: %d.%d.%d\n",
			compile_version.major,                                                        
			compile_version.minor,                                                        
			compile_version.patch);

	printf("running with SDL_image version: %d.%d.%d\n",
			link_version->major,
			link_version->minor, 
			link_version->patch);
}

int SDL_mixver(){
	SDL_version compile_version;
	const SDL_version *link_version=Mix_Linked_Version();
	SDL_MIXER_VERSION(&compile_version);
	printf("compiled with SDL_mixer version: %d.%d.%d\n",
			compile_version.major,
			compile_version.minor,
			compile_version.patch);
	
	printf("running with SDL_mixer version: %d.%d.%d\n",
			link_version->major,
			link_version->minor,
			link_version->patch);
}

int main(int argc, char *args[]){
	
	SDL_imgver();
	SDL_mixver();
}

