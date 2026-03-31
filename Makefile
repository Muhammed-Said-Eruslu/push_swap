NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

GREEN   = \033[1;32m
CYAN    = \033[1;36m
RED     = \033[1;31m
RESET   = \033[0m

SRC     = calculate_disorder.c complex_utils.c error.c find_value.c \
          lib.c lib_utils.c main.c medium_utils.c mem_str_lib.c parser.c \
          push.c reverse_rotate.c rotate.c simple_utils.c sort.c swap.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)  [LINK]$(RESET) $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)  [CC]$(RESET) $<"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)  [RM]$(RESET) *.o"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)  [RM]$(RESET) $(NAME)"

re: fclean all

.PHONY: all clean fclean re