/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:12:59 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/22 08:40:29 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_object(t_game *game, void *image, int x, int y)
{
	x *= game->size;
	y *= game->size;
	mlx_put_image_to_window(game->mlx, game->window, image, x, y);
}

void	draw_map(t_game *game, char **map)
{
	int		x;
	int		y;

	x = -1;
	while (map[++x] != NULL)
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == '1')
				draw_object(game, game->staticobjects->wall, y, x);
			else if (map[x][y] == 'C')
				draw_object(game, game->staticobjects->coin, y, x);
			else if (map[x][y] == 'E' && game->coincount == game->score)
				draw_object(game, game->staticobjects->portal, y, x);
		}
	}
}

void	draw_character(void *mlx, void *window, t_character *chatacter)
{
	int	y;
	int	x;

	y = chatacter->positony;
	x = chatacter->positonx;
	mlx_put_image_to_window(mlx, window, (*chatacter->current), x, y);
}
