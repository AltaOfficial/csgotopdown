main: main.c screens.c gameobjects.c renderer.c ingame.c
	@echo "Main Execuatable Created"
	@gcc -o main main.c screens.c gameobjects.c renderer.c ingame.c

clean:
ifeq ($(OS),Windows_NT)
	@del main
else
	@rm main
endif
	@echo "Removed Main Execuatable"