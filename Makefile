STUDENT_ID=l446d901
LAB_NAME=hash-table-lab-3
GCC=g++
CFLAGS=-Wall -g -pedantic --std=c++11

FILES=Makefile main.cpp hash_table.cpp hash_table.hpp DoubleLL.hpp DoubleLL.cpp util.cpp util.hpp node.hpp node.cpp data.txt

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

build: DoubleLL util main node hash_table
	$(GCC) $(CFLAGS) -o main DoubleLL.o util.o main.o node.o hash_table.o

test:
	./main

util:
	$(GCC) $(CFLAGS) -c util.cpp -o util.o

DoubleLL: node
	$(GCC) $(CFLAGS) -c DoubleLL.cpp -o DoubleLL.o

node:
		$(GCC) $(CFLAGS) -c node.cpp -o node.o

hash_table: DoubleLL
		$(GCC) $(CFLAGS) -c hash_table.cpp -o hash_table.o

main: DoubleLL
	$(GCC) $(CFLAGS) -c main.cpp -o main.o

analyze-add-tail: DoubleLL node
	$(GCC) $(CFLAGS) -c analyze-add-tail.cpp -o analyze-add-tail.o
	$(GCC) $(CFLAGS) -o add_tail_test DoubleLL.o node.o analyze-add-tail.o
	./add_tail_test

analyze-delete: DoubleLL node
	$(GCC) $(CFLAGS) -c analyze-delete.cpp -o analyze-delete.o
	$(GCC) $(CFLAGS) -o delete_test analyze-delete.o DoubleLL.o node.o
	./delete_test

analyze-getPositionList: DoubleLL node
	$(GCC) $(CFLAGS) -c analyze-getPositionList.cpp -o analyze-gPL.o
	$(GCC) $(CFLAGS) -o analyze-gPL analyze-gPL.o DoubleLL.o node.o
	./analyze-gPL

analyze-matrix-equality: DoubleLL node hash_table
	$(GCC) $(CFLAGS) -c analyze-matrix-equality.cpp -o analyze-matrix-equality.o
	$(GCC) $(CFLAGS) -o MEtest analyze-matrix-equality.o hash_table.o DoubleLL.o node.o
	./MEtest

analyze-matrix-transpose: DoubleLL node hash_table
		$(GCC) $(CFLAGS) -c analyze-matrix-transpose.cpp -o analyze-matrix-transpose.o
		$(GCC) $(CFLAGS) -o TRANtest analyze-matrix-transpose.o hash_table.o DoubleLL.o node.o
		./TRANtest



clean:
	rm -rf main *.o rm $(ARCHIVE_FOLDER) $(ARCHIVE_FOLDER).tar.gz

tar:
	make clean
	mkdir $(ARCHIVE_FOLDER)
	cp -r $(FILES) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
