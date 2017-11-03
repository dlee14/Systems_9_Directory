all: dirinfo.c
	gcc -o test dirinfo.c
clean:
	rm *.o
run: all
	./test
