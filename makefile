/# 206396863
# natalisadikov2318@gmail.com

CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS =
SRCS = player.cpp catan.cpp board.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
TEST_SRCS = Test.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: catan

catan: $(OBJS)
	$(CXX) $(LDFLAGS) -o catan $(OBJS)
	> occupied.txt
	./catan

test: $(TEST_OBJS) $(filter-out main.o,$(OBJS))
	$(CXX) $(LDFLAGS) -o test $(TEST_OBJS) $(filter-out main.o,$(OBJS))
	./test

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS) catan test
