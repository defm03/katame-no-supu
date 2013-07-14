SDLHEADERS ?= /usr/include/SDL
CFLAGS := -std=c11 -Wall -pipe -I$(SDLHEADERS)
LIBS := -lSDL -lSDLmain -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL_gfx -lm
.PHONY : clean install uninstall
katame : obj
	$(CC) $(CFLAGS) $(LIBS) katame.o -o katame
obj:
	$(CC) $(CFLAGS) -c katame.c -o katame.o
clean:
	rm -f katame
	rm -f *.o
install:
	mkdir -p /usr/share/games/katame
	mv katame /usr/bin/katame
	cp res/* /usr/share/games/katame
uninstall:
	rm -rf /usr/share/games/katame
	rm -f /usr/bin/katame
reinstall:
	rm -rf /usr/share/games/katame 
	rm -f /usr/bin/katame
	mkdir -p /usr/share/games/katame
	mv katame /usr/bin/katame
	cp res/* /usr/share/games/katame
