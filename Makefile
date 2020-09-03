OBJS	= Execute.o FetchUnit.o HelperFunctions.o Instruction.o IQueue.o main.o Memory.o Pipeline.o Register.o Statistics.o
SOURCE	= Execute.cpp FetchUnit.cpp HelperFunctions.cpp Instruction.cpp IQueue.cpp main.cpp Memory.cpp Pipeline.cpp Register.cpp Statistics.cpp 
HEADER	= Execute.hpp FetchUnit.hpp HelperFunctions.hpp Instruction.hpp IQueue.hpp main.hpp Memory.hpp Pipeline.hpp Register.hpp Statistics.hpp 
OUT	= tool
CC	 = g++
FLAGS	 = -g -c 
LFLAGS	 =  -lstdc++

all: $(OBJS)
		#$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
		$(CC) -o $(OUT) $(OBJS) $(LFLAGS)


Execute.o : Execute.cpp
		$(CC) $(FLAGS) Execute.cpp

FetchUnit.o : FetchUnit.cpp
		$(CC) $(FLAGS) FetchUnit.cpp

HelperFunctions.o : HelperFunctions.cpp
		$(CC) $(FLAGS) HelperFunctions.cpp

Instruction.o : Instruction.cpp
		$(CC) $(FLAGS) Instruction.cpp

IQueue.o : IQueue.cpp
		$(CC) $(FLAGS) IQueue.cpp

main.o  : main.cpp
		$(CC) $(FLAGS) main.cpp

Memory.o : Memory.cpp
		$(CC) $(FLAGS) Memory.cpp

Pipeline.o : Pipeline.cpp
		$(CC) $(FLAGS) Pipeline.cpp

Register.o : Register.cpp
		$(CC) $(FLAGS) Register.cpp

Statistics.o : Statistics.cpp
		$(CC) $(FLAGS) Statistics.cpp


clean:
		rm -f $(OBJS) $(OUT)
