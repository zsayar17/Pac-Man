/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:35:35 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 20:19:26 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(void)
{
	perror("Map Error\n");
	exit(-1);
}

void	exitgame(t_game *game)
{
	int	i;

	i = -1;
	freemap(game->map, 0);
	freestatics(game, game->staticobjects);
	freecharacter(game, game->character);
	freeenemy(game, game->enemy);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	free(game);
	exit(1);
}
