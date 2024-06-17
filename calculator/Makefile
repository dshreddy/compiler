CC = gcc
# CFLAGS = -Wall
TARGET = calculator.out
SRCS = lex.yy.c y.tab.c 
DEPS = y.tab.h

all: $(TARGET)

lex.yy.c: calculator.l
	lex $<

y.tab.c y.tab.h: calculator.y
	yacc -d $<

$(TARGET): lex.yy.c y.tab.c $(DEPS)
	$(CC) -o $@ $(SRCS)

clean:
	rm -f $(TARGET) lex.yy.c y.tab.c y.tab.h