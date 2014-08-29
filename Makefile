PROG_NAME = run.out
COMMON_DIR = common
ALGOS_DIR = algos
OBJS = $(COMMON_DIR)/common.o $(ALGOS_DIR)/string_matcher.o
CC = g++
DEBUG = -g
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PROG_NAME)

$(COMMON_DIR)/common.o : $(COMMON_DIR)/common.cpp $(COMMON_DIR)/common.h
	$(CC) $(CFLAGS) $(COMMON_DIR)/common.cpp -o $(COMMON_DIR)/common.o

$(ALGOS_DIR)/string_matcher.o : $(ALGOS_DIR)/string_matcher.cpp $(ALGOS_DIR)/string_matcher.h $(COMMON_DIR)/common.h
	$(CC) $(CFLAGS) $(ALGOS_DIR)/string_matcher.cpp -o $(ALGOS_DIR)/string_matcher.o


clean:
	rm $(COMMON_DIR)/*.o $(ALGOS_DIR)/*.o $(PROG_NAME) 
