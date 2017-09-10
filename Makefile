STUDENT_ID=l446d901
LAB_NAME=doubly-linked-list-lab-1
GCC=g++
CFLAGS=-Wall -g -pedantic --std=c++11

FILES=Makefile main.cpp DoubleLL.hpp DoubleLL.cpp util.cpp util.hpp node.hpp node.cpp data.txt

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

build: DoubleLL util main node SparseMatrix
	$(GCC) $(CFLAGS) -o main DoubleLL.o util.o main.o node.o SparseMatrix.o

test:
	./main

util:
	$(GCC) $(CFLAGS) -c util.cpp -o util.o

DoubleLL: node
	$(GCC) $(CFLAGS) -c DoubleLL.cpp -o DoubleLL.o

node:
		$(GCC) $(CFLAGS) -c node.cpp -o node.o

SparseMatrix: DoubleLL
		$(GCC) $(CFLAGS) -c SparseMatrix.cpp -o SparseMatrix.o

main: DoubleLL
	$(GCC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -rf main *.o rm $(ARCHIVE_FOLDER) $(ARCHIVE_FOLDER).tar.gz

tar:
	make clean
	mkdir $(ARCHIVE_FOLDER)
	cp -r $(FILES) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
