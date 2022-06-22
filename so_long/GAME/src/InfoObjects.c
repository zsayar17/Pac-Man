/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InfoObjects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:16:18 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 18:51:30 by aozsayar         ###   ########.fr       */
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
