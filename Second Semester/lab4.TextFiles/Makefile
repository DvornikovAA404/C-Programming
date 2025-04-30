all: a.out
	./build/a.out input.txt

a.out: build
	gcc task.c -o build/a.out

build:
	mkdir build

clear:
	rm build/task?.txt build/a.out && rmdir build