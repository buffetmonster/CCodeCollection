CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

TARGET = getline-OO_cpp
SRCS = $(TARGET).cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	$(RM) $(OBJS) $(TARGET)