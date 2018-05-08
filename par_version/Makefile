CFLAGS = -std=c++11 -Wall   
BOOST_PATHS = -I ../libs/boost_1_67_0 -I ../libs/boost_1_67_0/boost/mpi

all: main.o pugixml.o xml_parse.o node.o trie.o
	mpic++ $(CFLAGS) $(BOOST_PATHS)  $^ -o main ../libs/boost_1_67_0/install_dir/lib/libboost_mpi.a ../libs/boost_1_67_0/install_dir/lib/libboost_serialization.a

main.o: main.cpp main.hpp xml_parse.hpp trie.hpp node.hpp
	mpic++ $(CFLAGS) $(BOOST_PATHS) -c main.cpp

xml_parse.o: xml_parse.cpp xml_parse.hpp pugixml.hpp
	mpic++ $(CFLAGS) $(BOOST_PATHS) -c xml_parse.cpp

node.o: node.cpp node.hpp
	mpic++ $(CFLAGS) $(BOOST_PATHS) -c node.cpp

trie.o: trie.cpp trie.hpp node.hpp
	mpic++ $(CFLAGS) $(BOOST_PATHS) -c trie.cpp

pugixml.o: pugiconfig.hpp pugixml.cpp pugixml.hpp
	mpic++ $(CFLAGS) $(BOOST_PATHS) -c pugixml.cpp

clean:
	rm -rf *.o main