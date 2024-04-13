CC=g++ -std=c++17
CPPFLAGS=-c -Wall -Wextra -Werror
TEST_FLAGS = -lgtest

OS := $(shell uname -s)
ifeq ($(OS), Linux)
    D_ENV=__LINUX__
    TEST_FLAGS += -lrt -lpthread -lsubunit -lm
    OPEN_GCOV= xdg-open coverage/src/index.html
else
    D_ENV=__MAC_OS__
    OPEN_GCOV= open coverage/index.html
endif

TARGET = matrix

CPP_FILES = matrix.cpp
O_FILES = matrix.o

all: clean matrix.a test

matrix.a:
	@$(CC) $(CPPFLAGS) $(CPP_FILES) -D$(D_ENV)
	@ar rc lib$(TARGET).a $(O_FILES)
	@ranlib lib$@
	@cp lib$(TARGET).a $(TARGET).a
	@rm *.o

clean:
	@rm -rf *.out *.o *.a Test

test:
	@$(CC) $(CPP_FILES) test.cpp $(TEST_FLAGS) -D$(D_ENV) -o Test
	@./Test

leaks:
	@leaks -atExit -- ./Test 
