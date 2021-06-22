# g++ compiler 參數
CXX     := g++ 
CXXFLAG := -Wall -Werror -std=c++17
# CXXFLAG 可以加 -pedantic 告訴 G++ follow C++ rule.

all: program

program: main.o
	$(CXX) $(CXXFLAG) main.o -o $@ 

main.o: main.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

.PHONY: clean

clean:
	rm -rf ${OBJS} program