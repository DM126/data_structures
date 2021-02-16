CC=gcc
FLAGS=-g -Wall #-O3
OUTFILE=a.out
DEPS = node.h queue.h ../error.h
OBJ = driver.o node.o queue.o ../error.o

#Create object files
%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $< -o $@

#Create executable
all: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(OUTFILE)

clean:
	rm *.o ../*.o $(OUTFILE)
