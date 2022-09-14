sprint: main.o stringvalid.o createList.o addToList.o validAdd.o invalidFile.o assignJob.o displayList.o
	gcc -o bin/sprint.exe bin/main.o bin/stringvalid.o bin/createList.o bin/addToList.o bin/validAdd.o bin/invalidFile.o bin/assignJob.o bin/displayList.o

projtest: testdriver.o stringvalid.o testsuite.o
	gcc -o bin/projtest.exe bin/testdriver.o bin/stringvalid.o bin/testsuite.o -lcunit

testdriver.o: src/testdriver.c
	gcc -o bin/testdriver.o -c src/testdriver.c

testsuite.o: src/testsuite.c
	gcc -o bin/testsuite.o -c src/testsuite.c

main.o: src/main.c
	gcc -o bin/main.o -c src/main.c

stringvalid.o: src/stringvalid.c
	gcc -o bin/stringvalid.o -c src/stringvalid.c

createList.o: src/createList.c
	gcc -o bin/createList.o -c src/createList.c

addToList.o: src/addToList.c
	gcc -o bin/addToList.o -c src/addToList.c

validAdd.o: src/validAdd.c
	gcc -o bin/validAdd.o -c src/validAdd.c

invalidFile.o: src/invalidFile.c
	gcc -o bin/invalidFile.o -c src/invalidFile.c

displayList.o: src/displayList.c
	gcc -o bin/displayList.o -c src/displayList.c

assignJob.o: src/assignJob.c
	gcc -o bin/assignJob.o -c src/assignJob.c

clean:
	rm ./bin/*.exe ./bin/*.o invalidRecord.txt Schedule1.txt Schedule2.txt Schedule3.txt
