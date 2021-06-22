# gcc compiler 參數
CC      := gcc
CFLAGS  := -g -Wall -Werror -std=c99
# g++ compiler 參數
CXX     := g++ 
CXXFLAG := -Wall -Werror -std=c++17 -pedantic
# CXXFLAG 可以加 -pedantic 告訴 G++ follow C++ rule.

# 宣告 source 資料夾
SRC_DIRS = ./source
# 把 source 資料夾裡的 cpp 跟 c 全部找出來
SRCS := $(shell find $(SRC_DIRS) -name "*.cpp" -or -name "*.c")
# 取檔名並把副檔名加上 .o
OBJS := $(addsuffix .o,$(notdir $(SRCS))) main.o

# src  := $(wildcard */*.c */*.cpp)
# dir  := $(notdir $(src))
# obj  := $(patsubst %.c,%.o,$(dir))
# obj  := $(patsubst %.cpp,%.o,$(obj))

# include 參數
INC_DIRS  := ./include 
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

all: program

program: $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $@ 

main.o: main.cpp
	$(CXX) $(INC_FLAGS) $(CXXFLAG) -c $< -o $@

# .cpp.o 找 .cpp 編譯
%.cpp.o: $(SRC_DIRS)/%.cpp
	$(CXX) $(INC_FLAGS) $(CXXFLAG) -c $< -o $@

# .c.o 找 .c 編譯
%.c.o: $(SRC_DIRS)/%.c
	$(CC)  $(INC_FLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf ${OBJS} program