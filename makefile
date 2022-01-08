.PHONY: all
all:
	@gcc -Wall main.c -o game
	@./game
	@rm -f game