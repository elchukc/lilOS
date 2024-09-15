FILES=./build/blank.o ./build/start.o
INCLUDES=

all: $(FILES)
	i686-elf-gcc -g -T ./linker.ld -o ./blank.elf -ffreestanding -O0 -nostdlib -fpic -g $(FILES)

./build/blank.o: ./blank.c
	i686-elf-gcc $(INCLUDES) -I./$(FLAGS) -std=gnu99 -c ./blank.c -o ./build/blank.o

./build/start.o: ./start.asm
	nasm -f elf ./start.asm -o ./build/start.o

clean:
	rm -rf $(FILES) ./build/blank.o
	rm ./blank.elf