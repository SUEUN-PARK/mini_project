corona: corona19.c manager.o confirmer.o
	gcc -o corona corona19.c manager.o confirmer.o

manager.o: manager.c corona.h
	gcc -c manager.c -o manager.o

confirmer.o: confirmer.c corona.h
	gcc -c confirmer.c -o confirmer.o

clean:
	rm *.o corona
