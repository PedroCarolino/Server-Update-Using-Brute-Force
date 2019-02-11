CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c99 -pedantic
DEPS = funcoes.h
Vflags = valgrind --leak-check=full
OBJ = main.o funcoes.c
%.o: %.c $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

tp3: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

	rm -rf *.o

clean: 
	rm -rf *.o tp3

teste: tp3 
	$(Vflags) ./tp3 < entrada1.txt
	$(Vflags) ./tp3 < entrada2.txt
	$(Vflags) ./tp3 < entrada3.txt
	$(Vflags) ./tp3 < entrada4.txt
	$(Vflags) ./tp3 < entrada5.txt
	$(Vflags) ./tp3 < entrada6.txt
	$(Vflags) ./tp3 < entrada7.txt
	$(Vflags) ./tp3 < entrada8.txt
	$(Vflags) ./tp3 < entrada9.txt
	$(Vflags) ./tp3 < entrada10.txt
	$(Vflags) ./tp3 < entrada11.txt
	$(Vflags) ./tp3 < entrada12.txt








 
