USER_DIR = ./src

CXXFLAGS += -g -Wall -Wextra -lboost_program_options -lboost_unit_test_framework -lgmp

OBJS=test.o

all:	$(OBJS) 
	$(CXX) $(CXXFLAGS) $^ -o program

clean:	
	rm -f test.o program 
run:	
	./program
test.o:	$(USER_DIR)/test.cpp
	$(CXX) -c $(USER_DIR)/test.cpp -o test.o
