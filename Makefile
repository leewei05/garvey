CXX = clang++
CXXFLAGS = -g -Wall -Werror -std=c++14

PRGM  = grvy
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean test

all: $(PRGM) test

$(PRGM): $(OBJS)
	$(CXX) $(OBJS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS) $(PRGM)

test:
	./$(PRGM) test/hello.cpp

-include $(DEPS)
