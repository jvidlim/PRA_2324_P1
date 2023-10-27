bin/all: testNode.cpp testListArray.cpp testListLinked.cpp List.h Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h
	g++ -o bin/testListArray testListArray.cpp List.h
	g++ -o bin/testListLinked testListLinked.cpp Node.h List.h

clean:
	rm -r bin
