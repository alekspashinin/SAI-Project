CC = gcc
CFLAGS = -Wall
LIBS = -lGL -lGLU -lglut -lm -ljpeg
PROG = sai
SRCS = colision.o person.o eau.o dessiner.o ia.o main.o


$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

main.o:main.c dessiner.h
	$(CC) -c $(CFLAGS) main.c $(LIBS)

ia.o:ia.c ia.h
	$(CC) -c $(CFLAGS) ia.c


dessiner.o: dessiner.c dessiner.h
	$(CC) -c $(CFLAGS) dessiner.c $(LIBS)

eau.o: eau.c eau.h
	$(CC) -c $(CFLAGS) eau.c $(LIBS)


person.o:person.c person.h
	$(CC) -c $(CFLAGS) person.c

colision.o: colision.c colision.h
	$(CC) -c $(CFLAGS) colision.c 



clean:
	rm -f $(PROG)
	rm -f *.o


