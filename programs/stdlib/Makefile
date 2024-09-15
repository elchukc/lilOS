FILES=./build/start.o ./build/lilos.o
INCLUDES=

all: $(FILES)
	i686-elf-ld -m elf_i386 -relocatable $(FILES) -o ./stdlib.elf

./build/start.o: ./src/start.asm
	nasm -f elf ./src/start.asm -o ./build/start.o

./build/lilos.o: ./src/lilos.asm
	nasm -f elf ./src/lilos.asm -o ./build/lilos.o

clean:
	rm -rf $(FILES)
	rm ./stdlib.elf