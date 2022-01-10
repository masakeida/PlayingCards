CC	= c++
CFLAGS	=
TARGET	= PlayingCards
SRCS	= main.cpp card.cpp suit.cpp deck.cpp deal.cpp table.cpp
OBJS	= $(SRCS:.cpp=.o)
INCDIR	= -I../include
LIBDIR	=
LIBS	=

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBDIR) $(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
