CC=gcc
FLAGS=-g -Wall #-O3
OUTFILE=a.out
DEPS = treenode.h tree.h ../error.h
OBJ = driver.o treenode.o tree.o ../error.o

#Create object files
%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $< -o $@

#Create executable
all: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(OUTFILE)

clean:
	rm *.o ../*.o $(OUTFILE)
