CXX=g++-6 
CXXFLAGS= -Wall -c -g  
INCLUDES=-I/usr/include/python2.7  
TARGET=main  

$(TARGET):    
	$(CXX) $(CXXFLAGS) Doubly_LinkedList.h Doubly_LinkedList.cpp $(INCLUDES) Doubly_LinkedList.cpp
	$(CXX) $(CXXFLAGS) Graph.h Graph.cpp $(INCLUDES) Graph.cpp
	$(CXX) $(CXXFLAGS) Doubly_LinkedList.h Doubly_LinkedList.cpp Graph.h Graph.cpp Dijkstra.h Dijkstra.cpp $(INCLUDES) Dijkstra.cpp     
	$(CXX) $(CXXFLAGS) Doubly_LinkedList.h Doubly_LinkedList.cpp Graph.h Graph.cpp Dijkstra.h Dijkstra.cpp main.cpp $(INCLUDES) main.cpp
	$(CXX) -o $@ Doubly_LinkedList.o Graph.o Dijkstra.o main.o $(INCLUDES) -lpython2.7

clean:  
	rm -f $(TARGET) *.gch *.o