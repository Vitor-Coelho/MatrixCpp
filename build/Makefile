PROG  = test
CC    = g++
FLAGS = -Wall
SRCS  = ..\main.cpp ..\matrix.cpp
OBJS  = main.o matrix.o

$(PROG):
	$(CC) -c $(SRCS) $(FLAGS)
	$(CC) $(OBJS) $(FLAGS) -o $(PROG)

clean:
	del $(PROG).exe $(OBJS)
