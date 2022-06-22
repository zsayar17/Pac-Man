/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:12:59 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 09:54:01 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_object(t_game *game, void *image, int x, int y)
{
	x *= game->size;
	y *= game->size;
	mlx_put_image_to_window(game->mlx, game->window, image, x, y);
}

void	draw_stepcount(t_game *game)
{
	t_image	*number;
	int		pos[2];
	int		count;
	int		index;
	int		delimeter;

	index = -1;
	pos[0] = (game->mapsizex * game->size / 2) - 16;
	pos[1] = game->mapsizey * game->size;
	number = game->staticobjects->numbers;
	while (++index < 4)
	{
		count = (game->stepcount / ft_pow(10, 3 - index)) % 10;
		delimeter = -1;
		while (++delimeter < count)
			number = number->next;
		pos[0] += 8;
		mlx_put_image_to_window(game->mlx, game->window, number->image \
			, pos[0], pos[1]);
		number = game->staticobjects->numbers;
	}
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
				draw_object(game, game->staticobjects->wall->image, y, x);
			else if (map[x][y] == 'C')
				draw_object(game, game->staticobjects->coin->image, y, x);
			else if (map[x][y] == 'E' && game->coincount != game->score)
				draw_object(game, game->staticobjects->powerup->image, y, x);
			else if ((map[x][y] == 'E' || map[x][y] == 'e')
				&& game->coincount == game->score)
				draw_object(game, game->staticobjects->portal->image, y, x);
		}
	}
}

void	draw_character(void *mlx, void *window, t_character *chatacter)
{
	int	y;
	int	x;

	y = chatacter->positony;
	x = chatacter->positonx;
	mlx_put_image_to_window(mlx, window, (*chatacter->current)->image, x, y);
}

void	draw_enemies(t_game *game)
{
	int	i;

	i = -1;
	if (game->character->isdied == DIED)
		return ;
	while (++i < game->enemycount)
		draw_character(game->mlx, game->window, game->enemy[i]);
}
