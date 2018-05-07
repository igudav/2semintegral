CC=gcc
ASM=nasm
CFLAGS=-g -O2 -m32
ASMFLAGS=-g -f elf32

all: main

main: main.o allthemath.o f1.o f2.o f3.o f4.o f5.o f6.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

allthemath.o: allthemath.c
	$(CC) $(CFLAGS) -c $< -o $@

f1.o: f1.asm
	$(ASM) $(ASMFLAGS) $< -o $@

f2.o: f2.asm
	$(ASM) $(ASMFLAGS) $< -o $@

f3.o: f3.asm
	$(ASM) $(ASMFLAGS) $< -o $@

f4.o: f4.asm
	$(ASM) $(ASMFLAGS) $< -o $@

f5.o: f5.asm
	$(ASM) $(ASMFLAGS) $< -o $@

f6.o: f6.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -rf *.o
