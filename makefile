CC = gcc
AR = ar
MAINOBJECTS = main.o
LIBOBJECTS = myBank.o myBank.h
LIBa = libmyBank.a
LIBso = libmyBank.so
FLAGS = -Wall -g

all:  myBankd myBanks mains maind
mains: $(MAINOBJECTS) $(LIBa)
	$(CC) $(FLAGS)  -o mains $(MAINOBJECTS)  $(LIBa)

maind: $(MAINOBJECTS)
	$(CC) $(FLAGS)  -o maind $(MAINOBJECTS)  ./$(LIBso)
	
myBankd: $(LIBOBJECTS) 
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
myBanks: $(LIBOBJECTS) 
	$(AR) -rcs $(LIBa) $(LIBOBJECTS)
	
myBank.o: myBank.c myBank.h
	$(CC) -fPIC $(FLAGS)  -c myBank.c
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.o  *.out mains maind main $(LIBa) $(LIBso)
	
.PHONY:  clean all
