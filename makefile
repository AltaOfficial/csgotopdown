main: main.c screens.c gameobjects.c renderer.c ingame.c utilities.c
ifeq ($(OS),Windows_NT)
	@gcc -o main main.c screens.c gameobjects.c renderer.c ingame.c utilities.c
else
	@gcc -lncurses -o main main.c screens.c gameobjects.c renderer.c ingame.c utilities.c
endif
	@echo Main Execuatable Created

clean:
ifeq ($(OS),Windows_NT)
	@del "main.exe"
else
	@rm main
endif
	@echo Removed Main Execuatable