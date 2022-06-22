#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (-1);
	game = (t_game *)malloc(sizeof(t_game));
	setup(game, argv[1]);
	mlx_hook(game->window, 2, 1, keyprocessing, game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
}
