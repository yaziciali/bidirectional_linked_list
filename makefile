hepsi: derle calistir
derle:
	g++ -I ./include -o ./lib/node.o -c ./src/node.cpp
	g++ -I ./include -o ./lib/iterator.o -c ./src/iterator.cpp
	g++ -I ./include -o ./lib/linkedList2.o -c ./src/linkedList2.cpp
	g++ -I ./include -o ./bin/main ./lib/node.o ./lib/iterator.o ./lib/linkedList2.o ./src/main.cpp
calistir:
	./bin/main
	