# set compiler
CC = clang++
# include files
INCLUDE = -I ./include
#compilers flags for compiling object files
CFLAGSO = -std=c++14 -Wall -m64 -O3 -c ${INCLUDE}
# libraries
LIBS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
#compilers flags for compiling binary file
CFLAGSB = -s ${LIBS}

default: objCompile
	mkdir -p ./bin/release
	${CC} ./bin/build/*.o -o ./bin/release/main ${CFLAGSB}
	cp -R -n ./res ./bin/release/res

objCompile: 
	mkdir -p ./bin/build
	${CC} ./src/*.cpp ${CFLAGSO}
	# laymans way to move object files to make/build folder 
	mv *.o ./bin/build

clean: 
	rm -rf ./bin/build 
	rm -rf ./bin/release