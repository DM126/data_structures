CC=gcc
FLAGS=-g -Wall #-O3
OUTFILE=a.out
DEPS = sorting.h
OBJ = driver.o sorting.o

#Create object files
%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $< -o $@

#Create executable
all: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(OUTFILE)

clean:
	rm *.o $(OUTFILE)
