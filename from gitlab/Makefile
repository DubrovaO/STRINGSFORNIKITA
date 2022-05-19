CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 
CCOV = -fprofile-arcs -ftest-coverage
GFLAGS = --coverage
LDFLAGS = -lgcov
TFLAGS = -lcheck


all: test s21_string.a gcov_report


s21_string.a: s21_string.o s21_sprintf.o helpers.o
	ar rcs s21_string.a s21_string.o s21_sprintf.o helpers.o
	ranlib s21_string.a

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c

s21_sprintf.o: s21_sprintf.c
	$(CC) $(CFLAGS) -c s21_sprintf.c

helpers.o: helpers.c
	$(CC) $(CFLAGS) -c helpers.c


s21_string_test.o: s21_string_test.check
	checkmk sprintf.check > test_sprintf.c
	checkmk clean_mode=1 s21_string_test.check > s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c


test: s21_string.a s21_string_test.o 
	$(CC) $(CCOV) s21_string_test.o s21_string.a -o test $(TFLAGS) $(ADD_FLAGS)
	./test
	
gcov_report: s21_string.a s21_string_test.o test_sprintf.o
	$(CC) $(GFLAGS) $(ADD_FLAGS) s21_string_test.c s21_string.c s21_sprintf.c  s21_string.a -L. s21_string.a $(TFLAGS) -o ./s21_string_test.out
	./s21_string_test.out
	lcov -t "s21_string_test" -o test.info -c -d .
	genhtml -o report test.info
	

check:
	cppcheck *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c
	CK_FORK=no leaks --atExit -- ./s21_string_test.out

clean:
	rm -rf *.o *.a *.css *.html *.gcno *.gcda *.out *.info s21_string_test.c tests report


rebuild: clean all