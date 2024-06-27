CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++20

TARGET = manipulation
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
