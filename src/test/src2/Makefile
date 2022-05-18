CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 
CCOV = -fprofile-arcs -ftest-coverage
GFLAGS = --coverage
LDFLAGS = -lgcov
TFLAGS = -lcheck -lm -lpthread
UNAME:=$(shell uname -s)
ifeq ($(_UNAME_),Linux)
	ADD_FLAGS = -lrt -lsubunit
endif
ifeq ($(_UNAME_),Darwin)
	ADD_FLAGS =
endif


all: test s21_string.a gcov_report


s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c 

s21_string_test.o: s21_string_test.check
	checkmk clean_mode=1 s21_string_test.check > s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c

test: s21_string.a s21_string_test.o
	$(CC) $(CCOV) s21_string_test.o s21_string.a -o test -lcheck $(ADD_FLAGS)
	./test
	
gcov_report: s21_string.a s21_string_test.o
	$(CC) $(GFLAGS) $(ADD_FLAGS) s21_string_test.c s21_string.c s21_string.a -L. s21_string.a $(TFLAGS) -o ./s21_string_test.out
	./s21_string_test.out
	lcov -t "s21_string_test" -o test.info -c -d .
	genhtml -o report test.info
	

check:
	cppcheck *.h *.c
ifeq ("","$(wildcard ./CPPLINT.cfg)")
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
endif
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	CK_FORK=no leaks --atExit -- ./test

clean:
	rm -rf *.o *.a *.css *.html *.gcno *.gcda *.out *.info s21_string_test.c tests report


rebuild: clean all