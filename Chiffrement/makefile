SOURCES = $(wildcard *.c)
BINAIRES = $(patsubst %.c, %.o, ${SOURCES})
GCC = gcc

all: affichageresultat.o demandeutilisateur.o gestionchar.o menu.o modificationcesar.o modificationvigenere.o main

main: ${BINAIRES}
	${GCC} $^ -o $@

%.o: %.c %.h
	${GCC} -c $<

clear:
	rm *.o
	rm main