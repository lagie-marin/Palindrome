##
## EPITECH PROJECT, 2024
## B-SYN-200-LYN-2-1-palindrome-marin.lagie
## File description:
## Makefile
##
SRC = ./src/main.c \
	./src/init_config.c \
	./src/error/invalid_args.c \
	./src/process.c \
	./src/transform/transform.c \
	./src/utils/is_palindrome.c \
	./src/utils/my_revstr.c \
	./src/utils/maths/convertion.c \
	./src/utils/maths/my_pow.c \
	./src/utils/str_isnum.c \

SRC_TEST = ./requirement.c \
	./tests/redirect/redirect_all_stdout.c \
	./tests/code/t_my_squareroot_synthesis.c \
	./tests/code/t_my_factrec_synthesis.c \

OBJ = ${SRC:.c=.o}
CFLAGS = -g3 -Wall -Wextra -Iinclude
NAME = palindrome
all: $(NAME)

$(NAME): $(OBJ)
	gcc ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests
	rm -f vgcore.*
fclean: clean
	rm -f ${NAME}
tests_run:
	gcc -o unit_tests ${SRC_TEST} ${CFLAGS} --coverage -lcriterion
	./unit_tests
	gcovr --exclude tests/
run: tests_run
re: fclean all
