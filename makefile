
DEFINES = 

#header files (.h)
INCLUDES = -I.\include
#source code (.c) 
SOURCES = $(wildcard src/*.c)
#output library
LIB = .\lib\hpml.a
LIB_DIR = .\lib
#compilation flags
CFLAGS = -m64
STATIC_LIB_COMPILATION_FLAGS = -rc
ARCHIVER = ar


OBJECTS =  $(filter-out ./src/main.o, $(addsuffix .o, $(basename $(SOURCES))))

all: release
.PHONY: main clean

%.o : %.c
	gcc $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: debug release

debug: DEFINES += -DGLOBAL_DEBUG
debug: main

release: DEFINES += -DGLOBAL_RELEASE
release: main

.PHONY: lib-static lib-static-debug lib-static-release
lib-static :  lib-static-release 
lib-static-debug: DEFINES += -DGLOBAL_DEBUG
lib-static-debug: $(LIB)
lib-static-release: DEFINES += -DGLOBAL_RELEASE
lib-static-release: $(LIB)

$(LIB_DIR) : 
	mkdir $@

$(LIB): $(OBJECTS) | $(LIB_DIR)
	$(ARCHIVER) $(STATIC_LIB_COMPILATION_FLAGS) $@ $^ 
	@echo [Log] hpml.a build successfully

main: ./src/main.o  $(LIB)
	gcc $(DEFINES) $(CFLAGS) $< $(LIB) -o $@

clean: 
	del $(addprefix src\, $(notdir $(OBJECTS))) src\main.o
	del main.exe
	del $(LIB)
	rmdir $(LIB_DIR)