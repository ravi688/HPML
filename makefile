
DEFINES = -DDEBUG

#header files (.h)
INCLUDES = -I.\include
#source code (.c) 
SOURCES = $(wildcard src/*.c)
#libraries
LIBS = -L.\lib
#compilation flags
CFLAGS = -m64


OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

all: main
.PHONY: main clean

%.o : %.c
	gcc $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

main: $(OBJECTS)
	gcc $(DEFINES) $(CFLAGS) $^ $(LIBS) -o $@

clean: 
	del $(addprefix src\, $(notdir $(OBJECTS)))
	del main.exe