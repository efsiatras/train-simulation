CC= g++
CFLAGS= -std=c++98

OBJECTS= train_simulation.o train.o waggon.o passenger.o

train_simulation: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o train_simulation

train_simulation.o: train_simulation.cc
	$(CC) $(CFLAGS) -c train_simulation.cc

train.o: train.cc
	$(CC) $(CFLAGS) -c train.cc

waggon.o: waggon.cc
	$(CC) $(CFLAGS) -c waggon.cc

passenger.o: passenger.cc
	$(CC) $(CFLAGS) -c passenger.cc


.PHONY: clean

clean:
	rm -f train_simulation $(OBJECTS)