FILES =	ft_printf.c\
		ft_putchar_count_fd.c\
		ft_puthex_count_lower.c\
		ft_puthex_count_upper.c\
		ft_putnbr_count_fd.c\
		ft_putstr_count_fd.c\
		ft_putunbr.c\
		ft_strlen.c\
		ft_putunbr.c

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(FILES:.c=.o)


%.o : %.c ft_printf.h
		@$(CC) $(FLAGS) -c $<
		@echo "Compiling $<"

$(NAME): $(OBJS)
	@ar -cr $(NAME) $(OBJS)
	@echo "Creating archive file"

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "Removing object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removing archive file" 

re: fclean all