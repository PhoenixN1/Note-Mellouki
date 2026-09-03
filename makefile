NAME		= libft.a
SRCS_DIR	= srcs
INCS_DIR	= includes
SRCS		= ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_swap.c
SRCS		:= $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS		= $(SRCS:.c=.o)
HEADERS		= $(INCS_DIR)/ft.h
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rc
RANLIB		= ranlib
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
