#######################################
#  cmd
GCC		= 	g++
RM		=	rm
CP		=   cp


######################################
# cflags

INCLUDE_DIR		:= -I.
INCLUDE_DIR     := -I./common
#INCLUDE_DIR     += -I../include
#INCLUDE_DIR     += -I../thirdparty/libevent/include

# -pg
CFLAGS 	:= $(INCLUDE_DIR) -g -DLOG_INFO -static

######################################
#  dflags
LIB_DIR		:= -L.
#LIB_DIR     += -L../lib
#LIB_DIR     += -L../thirdparty/libevent/lib

#LD_FLAGS    := -lpthread -levent -lm -lz -lrt
LD_FLAGS    := -lpthread -lm -lz -lrt

#######################################
#  make
TARGET     :=  main
OBJS 		= 	./main.o


%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

$%.o: %.c
	gcc $(CFLAGS) -c $< -o $@


.PHONY: all
all:  ${TARGET}


${TARGET}: $(OBJS)
	g++ $(LIB_DIR) -o ${TARGET} $(OBJS) $(LD_FLAGS)


.PHONY: clean
clean:
	rm *.o ${TARGET}


