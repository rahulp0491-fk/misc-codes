EXEC_NAME = run.out
COMMON_DIR = common
ALGOS_DIR = algos
CC = g++
DEBUG = -g
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

COMMON_OBJS = $(COMMON_DIR)/common.o
STRING_MATCHER_OBJS = $(ALGOS_DIR)/string_matcher.o

COMMON_DEPS = $(COMMON_DIR)/common.cpp $(COMMON_DIR)/common.h
STRING_MATCHER_DEPS = $(ALGOS_DIR)/string_matcher.cpp $(ALGOS_DIR)/string_matcher.h $(COMMON_DIR)/common.h

COMMON_MAIN = $(COMMON_DIR)/common.cpp
STRING_MATCHER_MAIN = $(ALGOS_DIR)/string_matcher.cpp

STRING_MATCHER = string_matcher

$(STRING_MATCHER) : $(COMMON_OBJS) $(STRING_MATCHER_OBJS)
	$(CC) $(LFLAGS) $(COMMON_OBJS) $(STRING_MATCHER_OBJS) -o $(EXEC_NAME)

$(COMMON_DIR)/common.o : $(COMMON_DEPS)
	$(CC) $(CFLAGS) $(COMMON_MAIN) -o $(COMMON_OBJS)

$(ALGOS_DIR)/string_matcher.o : $(STRING_MATCHER_DEPS)
	$(CC) $(CFLAGS) $(STRING_MATCHER_MAIN) -o $(STRING_MATCHER_OBJS)

clean:
	rm $(COMMON_DIR)/*.o $(ALGOS_DIR)/*.o $(EXEC_NAME) 
