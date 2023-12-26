TEST=ON

main: main.c
	@echo "Main Execuatable Created!"
	@gcc -o main main.c library.c

clean:
	ifeq ($(OS),Windows_NT)
		@echo "removed main"
		@del main.exe
		@del main.obj
	endif

test:
	@echo $(info $(SHELL))