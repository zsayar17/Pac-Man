/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:26:49 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/22 09:03:24 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (-1);
	checkname(argv[1]);
	game = (t_game *)malloc(sizeof(t_game));
	setup(game, argv[1]);
	mlx_hook(game->window, 2, 1, keyprocessing, game);
	mlx_hook(game->window, 17, (0L), destroy, game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
}
