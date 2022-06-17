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


# main.o :
# $(CC) $(CPPFLAGS) -c main.cpp

# blurb.o : blurb.h
# $(CC) $(CPPFLAGS) -c blurb.cpp

# database.o : database.h
# $(CC) $(CPPFLAGS) -c database.cpp

# clean:
# rm -f core $(PROG) $(OBJS)
