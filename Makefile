EXEC_NAME = run.out
ALGOS_DIR = algos
NT_DIR = $(ALGOS_DIR)/number-theory
SM_DIR = $(ALGOS_DIR)/string-matching
CC = g++
DEBUG = -g
OBJECT = -o
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

NT_OBJS = $(NT_DIR)/nt_common.o
SM_OBJS = $(SM_DIR)/string_matcher.o

OBJS = $(NT_OBJS) $(SM_OBJS)

NT_DEPS = $(NT_DIR)/nt_common.cpp $(NT_DIR)/nt_common.h
SM_DEPS = $(SM_DIR)/string_matcher.cpp $(SM_DIR)/string_matcher.h $(NT_DIR)/nt_common.h

NT_MAIN = $(NT_DIR)/nt_common.cpp
SM_MAIN = $(SM_DIR)/string_matcher.cpp

STRING_MATCHER = string_matcher

$(STRING_MATCHER) : $(SM_OBJS) $(NT_OBJS)
	$(CC) $(LFLAGS) $(SM_OBJS) $(NT_OBJS) $(OBJECT) $(EXEC_NAME)

$(NT_OBJS) : $(NT_DEPS)
	$(CC) $(CFLAGS) $(NT_MAIN) $(OBJECT) $(NT_OBJS)

$(SM_OBJS) : $(SM_DEPS)
	$(CC) $(CFLAGS) $(SM_MAIN) $(OBJECT) $(SM_OBJS)

clean:
	rm $(OBJS) $(EXEC_NAME) 
