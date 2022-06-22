CC			= gcc
MINILIBX	= ./mlx/libmlx.a -lm
NAME 		= so_long
FLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
BNAME		= so_long_bonus
SRCS 		= $(wildcard GAME/src/*.c)
OBJS 		= $(SRCS:.c=.o)
BSRCS		= $(wildcard GAME_BONUS/src/*.c)
BOBJS		= $(BSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./mlx/
	$(CC) $(FLAGS) $(LFLAGS) $(MINILIBX) $(OBJS) -o $(NAME)

bonus : $(BNAME)

$(BNAME) : $(BOBJS)
	$(MAKE) -C ./mlx/
	$(CC) $(FLAGS) $(LFLAGS) $(MINILIBX) $(BOBJS) -o $(BNAME)

run: all
	./$(NAME) maps/text.ber
re: fclean all
clean:
	rm -rf $(OBJS)
	rm -rf $(BOBJS)
norm:
	@norminette src/*.c
	@norminette bonus/*.c

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BNAME)
	@make clean -C mlx
.PHONY: clean run fclean re all
