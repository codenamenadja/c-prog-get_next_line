CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -Iincludes -D BUFFER_SIZE=32
.DEFAULT_GOAL		:= all
NAME				= get_next_line.out

SOURCES				= $(wildcard srcs/*.c)

.PHONY: all
all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $(NAME)

.PHONY: fclean
fclean:
	@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
