CXX = clang++
CXXFLAGS = -std=c++17

TARGET = main.o contact.o node.o contact_list.o tNode.o tree.o
SOURCES = main.cpp contact.cpp node.cpp contact_list.cpp tNode.cpp tree.cpp
HEADERS = at1.h

main: $(TARGET) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TARGET) -o main

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm -f main $(TARGET)

