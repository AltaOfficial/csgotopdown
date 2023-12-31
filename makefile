main: main.c screens.c gameobjects.c renderer.c ingame.c
	@echo "Main Execuatable Created!"
	@gcc -o main main.c screens.c gameobjects.c renderer.c ingame.c

clean:
	ifeq ($(OS),Windows_NT)
		@echo "removed main"
		@del main.exe
		@del main.obj
	endif
	ifeq ($(OS),Unix)
		@echo "my OS is: $(OS)"
		@rm main
	endif

test:
	@echo $(info $(SHELL))