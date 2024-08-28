PJ3:	main.o stack.o heap.o graph.o util.o
	g++ -o PJ3 main.o stack.o heap.o graph.o util.o
main.o:	main.cpp stack.h heap.h graph.h util.h
	g++ -c -Wall main.cpp
stack.o:stack.cpp stack.h
	g++ -c -Wall stack.cpp
heap.o:	heap.cpp heap.h
	g++ -c -Wall heap.cpp
graph.o:graph.cpp graph.h
	g++ -c -Wall graph.cpp
util.o: util.cpp util.h
	g++ -c -Wall util.cpp
