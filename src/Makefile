FLAGS= -Wall -g

katame.o: katame.c
	gcc -Wall -o katame.o katame.c `pkg-config --cflags --libs allegro-5.0` 

clean:
	rm -f katame.o
	rm -f katame.exe
