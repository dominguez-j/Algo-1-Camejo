CC = gcc
CFLAGS = -std=c99 -Werror -Wall -Wconversion -lm
SOURCE = *.c
OBJ = $(SOURCE: .c =.o)
EXE = juego 

all: $(SOURCE) $(EXE)

$(EXE): $(OBJ)
		$(CC) $(OBJ) -o $@

%.o: %.c
		$(CC) $(CFLAGS) $< -o $@
