libsetjmp_test.a: setjmp_test.o
	xtensa-esp32-elf-ar rcs libsetjmp_test.a setjmp_test.o

setjmp_test.o: setjmp_test.c setjmp_test.h
	xtensa-esp32-elf-gcc -c setjmp_test.c -o setjmp_test.o

clean:
	rm -f setjmp_test.o libsetjmp_test.a
