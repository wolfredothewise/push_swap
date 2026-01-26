# =========================
#        PROGRAM
# =========================

NAME = push_swap

# =========================
#        COMPILER
# =========================

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

# =========================
#        PATHS
# =========================

SRC_DIR = src
INC_DIR = includes

LIBFT_DIR = libft
PRINTF_DIR = ft_printf

# =========================
#        LIBRARIES
# =========================

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# =========================
#        SOURCES
# =========================

SRC = 	push_swap.c \
		stack_parse.c \
		ft_utils_checker.c \
		ft_sort_2_5.c \
		ft_instructions.c \
		ft_create_index.c\
		ft_sort_3.c\
		ft_sort_radix.c\
		ft_free.c


SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(SRCS:.c=.o)

# =========================
#        RULES
# =========================

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -I$(INC_DIR) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# =========================
#        LIB RULES
# =========================

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

# =========================
#        CLEAN
# =========================

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
