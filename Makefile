CC= g++
CXXFLAGS= -std=c++17 -pedantic -Wall -Wextra -Werror -Iincludes

VPATH=src

.PHONY: clean

OBJS= camera.o \
	main.o \
	screen.o \
	utils.o \
	vect.o \
	ray.o \
	plan.o \
	square.o \
	landmark.o \
	cube.o \
	pointlight.o \
	color.o \
	ambientlight.o \
	dirlight.o

all: opti

run: opti
	$(RM) test.ppm
	./main

opti: CXXFLAGS+= -O3
opti: main

main: $(OBJS)

debug: CXXFLAGS+= -g -O0
debug: main

doc:
	doxygen doc.doxygen
	cd latex; make

clean:
	$(RM) main test.ppm
	$(RM) $(OBJS)
	$(RM) -r html latex
