CC			= gcc
MINILIBX	= ./mlx/libmlx.a -lm
NAME 		= so_long
FLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
SRCS 		= $(wildcard Game_Loop/src/*.c)
OBJS 		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./mlx/
	$(CC) $(FLAGS) $(LFLAGS) $(MINILIBX) $(OBJS) -o $(NAME)

run: all
	./$(NAME) maps/text.ber
re: fclean all
clean:
	rm -rf $(OBJS)
norm:
	@norminette src/*.c
fclean: clean
	rm -rf $(NAME)
	@make clean -C mlx
.PHONY: clean run fclean re all
