main: main.c library.c gameobjects.c renderer.c
	@echo "Main Execuatable Created!"
	@gcc -o main main.c library.c gameobjects.c renderer.c

clean:
	ifeq ($(OS),Windows_NT)
		@echo "removed main"
		@del main.exe
		@del main.obj
	endif
	ifeq ($(OS),Unix)
		rm main
	endif

test:
	@echo $(info $(SHELL))