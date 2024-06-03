CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++23

TARGET = datatypes-OO_cpp
#TARGET = other
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