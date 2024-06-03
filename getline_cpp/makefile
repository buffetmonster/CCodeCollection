CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

TARGET = getline_cpp
SRCS = getline_cpp.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./getline_cpp

clean:
	$(RM) $(OBJS) $(TARGET)