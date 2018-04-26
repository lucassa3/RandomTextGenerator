CFLAGS = -std=c++11 -Wall  -I libs/boost_1_67_0 -I libs/pugixml-1.9/src/

all: main.o pugixml.o xml_parse.o node.o trie.o
		g++ $(CFLAGS)  $^ -o  main

main.o: main.cpp main.hpp xml_parse.hpp trie.hpp node.hpp
		g++ $(CFLAGS) -c  main.cpp

xml_parse.o: xml_parse.cpp xml_parse.hpp pugixml.hpp
		g++ $(CFLAGS) -c  xml_parse.cpp

node.o: node.cpp node.hpp
		g++ $(CFLAGS) -c  node.cpp

trie.o: trie.cpp trie.hpp node.hpp
		g++ $(CFLAGS) -c  trie.cpp

pugixml.o: pugiconfig.hpp pugixml.cpp pugixml.hpp
		g++ $(CFLAGS) -c pugixml.cpp

clean:
	rm -rf *.o main