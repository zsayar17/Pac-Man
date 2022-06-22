#include "../include/so_long.h"

int    loop(t_game *game)
{
    update(game);
    mlx_do_sync(game->mlx);
    draw(game);
    return (1);
}

void	setup(t_game *game, char *path)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 420, 420, "solong");
}

void	update(t_game *game)
{

}

void	draw(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
}


