CC=gcc
FLAGS=-g -Wall #-O3
OUTFILE=a.out
DEPS = stack.h ../error.h
OBJ = driver.o stack.o ../error.o

#Create object files
%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $< -o $@

#Create executable
all: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(OUTFILE)

clean:
	rm *.o ../*.o $(OUTFILE)
