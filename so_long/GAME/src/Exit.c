/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:35:35 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/22 09:03:44 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(void)
{
	perror("Map Error\n");
	exit(-1);
}

void	exitmap(char **map, int iserror)
{
	int		i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
			free(map[i++]);
		free(map);
	}
	if (iserror)
		error();
}

void	exitgame(t_game *game)
{
	exitmap(game->map, 0);
	mlx_destroy_image(game->mlx, game->character->closed);
	mlx_destroy_image(game->mlx, game->character->left);
	mlx_destroy_image(game->mlx, game->character->right);
	mlx_destroy_image(game->mlx, game->character->down);
	mlx_destroy_image(game->mlx, game->character->up);
	mlx_destroy_image(game->mlx, game->staticobjects->coin);
	mlx_destroy_image(game->mlx, game->staticobjects->portal);
	mlx_destroy_image(game->mlx, game->staticobjects->wall);
	free(game->character);
	free(game->staticobjects);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	exit(0);
}
