all	:test_simple.o hashtable.o test_advanced.exe test.o test_time.exe
	gcc test_simple.o hashtable.o -o test_simple.exe
test_advanced.exe	: test_advanced.o hashtable.o test.o
	gcc test_advanced.o hashtable.o test.o -o test_advanced.exe
test_time.exe	: test_time.o hashtable.o test.o
	gcc test_time.o hashtable.o test.o -o test_time.exe
test_time.o	:test_time.c hashtable.h test.h
	gcc -I . -Wall -c test_time.c
test_advanced.o	:test_advanced.c hashtable.h test.h
	gcc -I . -Wall -c test_advanced.c
test_simple.o 	:test_simple.c hashtable.h
	gcc -I . -Wall -c test_simple.c
test.o  :test.c test.h
	gcc -I . -Wall -c test.c
hashtable.o	:hashtable.c hashtable.h
	gcc -I . -Wall -c hashtable.c
clean	:
	rm -rf *.o
	rm -rf *.exe
