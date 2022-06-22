/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UpdateDirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:39:48 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/22 08:40:37 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_pow(int x, int y)
{
	int	i;

	if (y == 0)
		return (1);
	i = 0;
	while (++i < y)
		x *= x;
	return (x);
}

void	write_stepcount(t_game *game)
{
	int		pos[2];
	int		count;
	int		index;
	char	c;

	index = -1;
	pos[0] = (game->mapsizex * game->size / 2) - 16;
	pos[1] = game->mapsizey * game->size;
	while (++index < 4)
	{
		count = (game->stepcount / ft_pow(10, 3 - index)) % 10;
		pos[0] += 8;
		c = '0' + count;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	updatedirection(t_character *character)
{
	if (character->movedirection == LEFT)
		character->current = &character->left;
	else if (character->movedirection == RIGHT)
		character->current = &character->right;
	else if (character->movedirection == UP)
		character->current = &character->up;
	else if (character->movedirection == DOWN)
		character->current = &character->down;
	else if (character->movedirection == WAIT)
		character->current = &character->closed;
}
