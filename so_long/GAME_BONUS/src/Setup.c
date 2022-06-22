/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:39:23 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 14:59:59 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	setup(t_game *game, char *path)
{
	int	sizex;
	int	sizey;

	game->map = get_map_dataa(path);
	game->mapsizex = ft_strlen(game->map[0]);
	game->mapsizey = linelen(game->map);
	game->iscatch = CATCH;
	game->size = 32;
	game->score = 0;
	game->delimeter = 0;
	game->stepcount = 0;
	game->coincount = get_object_count(game->map, 'C');
	game->mlx = mlx_init();
	sizex = game->mapsizex * game->size;
	sizey = game->mapsizey * game->size;
	game->window = mlx_new_window(game->mlx, sizex, sizey + 15, "PAC-MAN");
	game->character = createpacman(game);
	game->enemycount = get_object_count(game->map, 'N');
	game->enemy = createenemies(game);
	game->staticobjects = createobjects(game);
}
