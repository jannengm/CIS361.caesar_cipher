caesar: caesar.o
	gcc caesar.o -o caesar
caesar.o: caesar.c

test: test1 test2
test1:
	./caesar 1 cryptography data.txt data.out
test2:
	./caesar 2 cryptography data.out data.bak
	diff -s data.txt data.bak

clean:
	rm *.o
	rm *.out
	rm *.bak
	rm *caesar

retest: clean caesar test
