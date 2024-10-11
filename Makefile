SH = nu.exe
CC = clang
FLAGS = -Wall -Wextra -std=c99
C_OBJECT_LIST = build/main.o build/linkedList.o build/binaryTree.o

r: build
	./a

b: build
c: clean

build: ${C_OBJECT_LIST}
	${CC} ${FLAGS} $^

build/main.o: main.c
	${SH} -c "mkdir build"
	${CC} ${FLAGS} -c $^ -o $@

build/%.o: Src/%.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	${SH} -c "rm -v -rf build/*"
	${SH} -c "rm -v -f a.exe"
