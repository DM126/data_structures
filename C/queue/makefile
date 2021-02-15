CC=gcc
FLAGS=-g #-O3
OUTFILE=a.out
DEPS = queue.h ../error.h
OBJ = main.o queue.o ../error.o

#Create object files
%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $< -o $@

#Create executable
all: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(OUTFILE)

clean:
	rm *.o ../*.o $(OUTFILE)
