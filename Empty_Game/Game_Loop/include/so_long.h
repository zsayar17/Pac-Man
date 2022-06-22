#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include "../../mlx/mlx.h"

#define A 0
#define S 1
#define D 2
#define W 13
#define ESC 53

typedef struct s_game
{
	void	*mlx;
	void	*window;
} t_game;

int		loop(t_game *game);

int		keyprocessing(int keyevent, t_game *game);
void	setup(t_game *game, char *path);
void	update(t_game *game);
void	draw(t_game *game);

#endif
