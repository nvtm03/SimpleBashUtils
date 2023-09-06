flags = -Wall -Wextra -Werror -pedantic -ofast -std=c11 -IIncludes -g
all: s21_cat

s21_cat: main.o
	gcc $(flags) main.o -o s21_cat

main.o: main.c
	gcc $(flags) -c main.c -o main.o

clang:
	clang-format -n -style=google main.c
	clang-format -n -style=google main.h

cppcheck:
	cppcheck main.c
	cppcheck main.h

test:
	sh test_func_cat.sh

clean:
	rm -rf *.o s21_cat

