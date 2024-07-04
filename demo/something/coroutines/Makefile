
c20=-fcoroutines -std=c++20
c20=-std=c++2a -fcoroutines


all:
	g++ -g test.cc -lpthread -o test -Wall --save-temps -Wfatal-errors ${c20}
	g++ -g demo.cc -lpthread -o demo -Wall --save-temps -Wfatal-errors ${c20}
