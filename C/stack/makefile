CC=gcc
FLAGS=-g -Wall #-O3
OUTFILE=a.out
DEPS = stack.h ../error.h ../array_util.h
OBJ = driver.o stack.o ../error.o ../array_util.o

#Create object files
%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $< -o $@

#Create executable
all: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(OUTFILE)

clean:
	rm *.o ../*.o $(OUTFILE)
