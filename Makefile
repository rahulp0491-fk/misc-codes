EXEC_NAME = run.out
CC = g++
DEBUG = -g
OBJECT = -o
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

ALGOS_DIR = algos
NT_DIR = $(ALGOS_DIR)/number-theory
SM_DIR = $(ALGOS_DIR)/string-matching
GT_DIR = $(ALGOS_DIR)/graph

NT_OBJS = $(NT_DIR)/nt_common.o
SM_OBJS = $(SM_DIR)/string_matcher.o
GT_OBJS = $(GT_DIR)/traversal.o

OBJS = $(NT_OBJS) $(SM_OBJS) $(GT_OBJS)

NT_DEPS = $(NT_DIR)/nt_common.cpp $(NT_DIR)/nt_common.h
SM_DEPS = $(SM_DIR)/string_matcher.cpp $(SM_DIR)/sm_common.h $(NT_DIR)/nt_common.h
GT_DEPS = $(GT_DIR)/traversal.cpp $(GT_DIR)/graph_common.h

NT_MAIN = $(NT_DIR)/nt_common.cpp
SM_MAIN = $(SM_DIR)/string_matcher.cpp
GT_MAIN = $(GT_DIR)/traversal.cpp

STRING_MATCHER = string_matcher
GRAPH_TRAVERSAL = graph_traversal

$(STRING_MATCHER) : $(SM_OBJS) $(NT_OBJS)
	$(CC) $(LFLAGS) $(SM_OBJS) $(NT_OBJS) $(OBJECT) $(EXEC_NAME)

$(GRAPH_TRAVERSAL): $(GT_OBJS)
	$(CC) $(LFLAGS) $(GT_OBJS) $(OBJECT) $(EXEC_NAME)

$(NT_OBJS) : $(NT_DEPS)
	$(CC) $(CFLAGS) $(NT_MAIN) $(OBJECT) $(NT_OBJS)

$(SM_OBJS) : $(SM_DEPS)
	$(CC) $(CFLAGS) $(SM_MAIN) $(OBJECT) $(SM_OBJS)

$(GT_OBJS) : $(GT_DEPS)
	$(CC) $(CFLAGS) $(GT_MAIN) $(OBJECT) $(GT_OBJS)

clean:
	if [ -f $(EXEC_NAME) ]; \
	then \
		rm $(EXEC_NAME); \
	fi; \
	\
	for o in $(OBJS); \
	do \
		if [ -f $$o ]; \
		then \
			rm $$o; \
		fi; \
	done;

