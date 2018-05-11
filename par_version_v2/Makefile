CFLAGS = -std=c++11 -Wall

all: main.o pugixml.o xml_parse.o node.o trie.o
	mpic++ $(CFLAGS)   $^ -o main -lboost_mpi -lboost_serialization

main.o: main.cpp main.hpp xml_parse.hpp trie.hpp node.hpp
	mpic++ $(CFLAGS)  -c main.cpp

xml_parse.o: xml_parse.cpp xml_parse.hpp pugixml.hpp
	mpic++ $(CFLAGS)  -c xml_parse.cpp

node.o: node.cpp node.hpp
	mpic++ $(CFLAGS)  -c node.cpp

trie.o: trie.cpp trie.hpp node.hpp
	mpic++ $(CFLAGS)  -c trie.cpp

pugixml.o: pugiconfig.hpp pugixml.cpp pugixml.hpp
	mpic++ $(CFLAGS)  -c pugixml.cpp

clean:
	rm -rf *.o main