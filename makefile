all: forkin.o
	gcc forkin.o
forkin.o: forkin.c
	gcc -c forkin.c
run: a.out
	./a.out
clean: forkin.o
	rm forkin.o
again:
	emacs forkin.c
