CC=g++ -std=c++17
CPPFLAGS=-c -Wall -Wextra -Werror
TEST_FLAGS = -lgtest

OS := $(shell uname -s)
ifeq ($(OS), Linux)
    D_ENV=__LINUX__
    TEST_FLAGS += -lrt -lpthread -lsubunit -lm
    OPEN_GCOV= xdg-open coverage/coverage.html
else
    D_ENV=__MAC_OS__
    OPEN_GCOV= open coverage/coverage.html
endif

TARGET = matrix

CPP_FILES = matrix.cpp
O_FILES = matrix.o

all: clean matrix.a test gcov_report

matrix.a:
	@$(CC) $(CPPFLAGS) $(CPP_FILES) -D$(D_ENV)
	@ar rc lib$(TARGET).a $(O_FILES)
	@ranlib lib$@
	@cp lib$(TARGET).a $(TARGET).a
	@rm *.o

clean:
	@rm -rf *.out *.o *.a Test *.gcda *.gcno
	@rm -rf coverage

test:
	@$(CC) $(CPP_FILES) test.cpp $(TEST_FLAGS) -D$(D_ENV) -o Test --coverage
	@./Test

gcov_report:
	@mkdir coverage
	@cd coverage && gcovr -r .. --html-details=coverage.html
	@$(OPEN_GCOV)

leaks:
	@leaks -atExit -- ./Test 
