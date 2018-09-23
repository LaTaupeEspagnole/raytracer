CC= g++
CXXFLAGS= -std=c++17 -pedantic -Wall -Wextra -Werror -Iincludes -g

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
	color.o

all: main

run: main
	$(RM) test.ppm
	./main

main: $(OBJS)

clean:
	$(RM) main
	$(RM) $(OBJS)
