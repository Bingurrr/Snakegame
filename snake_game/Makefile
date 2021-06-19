CC = g++
CCFLAGS = -g

pro: main.o map.o snake.o Controll.o
	$(CC) $(CCFLAGS) -o pro main.o map.o snake.o Controll.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $<	
