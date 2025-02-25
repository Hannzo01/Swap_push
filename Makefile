SRCS = ft_split.c parse_input.c list_utils.c \
       operations-I.c operations-II.c push_swap.c \
       I-algo.c II-algo.c III-algo.c \
       list_utlis2.c parsing.c sorting.c \
       split_validate.c sort_large_stack.c

OBJ = $(SRCS:.c=.o)

BONUS_SRCS = checker_bonus.c ft_split_bonus.c \
			list_utils_bonus.c list_utlis2_bonus.c \
			parse_input_bonus.c parsing_bonus.c \
			split_validate_bonus.c gnl/get_next_line.c \
			gnl/get_next_line_utils.c validate_operations.c \
			operations_bonus.c operations2_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker

MANDATORY_HEADER = push_swap.h
BONUS_HEADER = push_swap_bonus.ht

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
	@touch bonus

%.o: %.c $(MANDATORY_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) bonus

re: fclean all

.PHONY: all clean fclean re 
