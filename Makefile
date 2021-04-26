AM_CFLAGS := -g -Wall -O2
CC	  := g++
CFLAGS	  := $(AM_CFLAGS)
LD	  := g++
APPS	  := it
OBJS	  := $(APPS).o
SRCS	  := $(APPS).cpp

it: it.o
	$(LD) $(AM_CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(APPS) *.o *.out
