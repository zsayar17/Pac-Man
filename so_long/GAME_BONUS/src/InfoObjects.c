/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InfoObjects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:16:18 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 03:31:50 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_character_pos(char **map)
{
	int		x;
	int		y;
	size_t	counter;

	y = -1;
	counter = 0;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				return ((y << 8) + x);
		}
	}
	return (0);
}

int	get_enemy_pos(char **map)
{
	static int	x;
	static int	y;

	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'N')
			{
				x++;
				return ((y << 8) + x - 1);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int	get_object_count(char **map, char c)
{
	int		x;
	int		y;
	size_t	counter;

	y = -1;
	counter = 0;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == c)
				counter++;
		}
	}
	return (counter);
}

const char	*get_color(void)
{
	static int	x;
	const char	*c;

	c = NULL;
	if (x == 0)
		c = RED;
	else if (x == 1)
		c = PINK;
	else if (x == 2)
		c = BLUE;
	else if (x == 3)
		c = ORANGE;
	else if (x == 4)
		c = PURPLE;
	else if (x == 5)
		c = YELLOW;
	if (x == 5)
		x = 0;
	x++;
	return (c);
}
