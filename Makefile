SH = nu.exe -l -c

CC = clang
EXTRAS = -gdwarf
FLAGS =  -Wall -Wextra -std=c11 ${EXTRAS}

C_OBJECT_LIST = $(patsubst Src/%.c, build/%.o, $(wildcard **/*.c *.c))

r: build
	./a

b: build
c: clean

build: ${C_OBJECT_LIST}
	${CC} ${FLAGS} $^

build/main.o: main.c
	${SH} "mkdir build"
	${CC} ${FLAGS} -c $^ -o $@

build/%.o: Src/%.c
	${CC} ${FLAGS} -c $< -o $@

dump: build
	${SH} "x86asm ./a.exe"

clean:
	${SH} "rm -v -rf build/*"
	${SH} "rm -v -f a.exe"
	${SH} "rm -v -f dump.asm"
