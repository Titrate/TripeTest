CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++0x

OBJS =	TrieNode.o Trie.o Tripe.o TxtFile.o Heap.o main.o

LIBS =

TARGET =	TripeTest


$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
