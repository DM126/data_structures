CC=g++
FLAGS=-g -Wall #-O3
OUTFILE=a.out
DEPS = queue.hpp node.hpp
OBJ = driver.o

#Create object files
%.o: %.cpp $(DEPS)
	$(CC) $(FLAGS) -c $< -o $@

#Create executable
all: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(OUTFILE)

clean:
	rm *.o $(OUTFILE)
