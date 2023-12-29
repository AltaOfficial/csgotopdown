main: main.c library.c gameobjects.c
	@echo "Main Execuatable Created!"
	@gcc -o main main.c library.c gameobjects.c

clean:
	ifeq ($(OS),Windows_NT)
		@echo "removed main"
		@del main.exe
		@del main.obj
	endif

test:
	@echo $(info $(SHELL))