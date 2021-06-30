CC=gcc
FLAGS=-g -Wall #-O3
OUTFILE=a.out
DEPS = hashtable.h ../error.h
OBJ = driver.o hashtable.o ../error.o

#Create object files
%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $< -o $@

#Create executable
all: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(OUTFILE)

clean:
	rm *.o ../*.o $(OUTFILE)
