CC = gcc
CFLAGS = -std=c99 -Werror -Wall -Wconversion
SOURCE = *.c
OBJ = $(SOURCE: .c =.o)
EXE = increidle 

all: $(SOURCE) $(EXE)

$(EXE): $(OBJ)
		$(CC) $(OBJ) -o $@

%.o: %.c
		$(CC) $(CFLAGS) $< -o $@
