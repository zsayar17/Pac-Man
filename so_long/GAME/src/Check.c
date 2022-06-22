/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:27:08 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/22 09:27:02 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	checkcount(char **map)
{
	if (get_object_count(map, 'P') != 1 || !get_object_count(map, 'C')
		|| !get_object_count(map, 'E'))
		exitmap(map, 1);
}

void	check_map(char **map)
{
	int		row;
	int		column;
	int		previousrow;
	int		currentrow;
	char	c;

	row = -1;
	previousrow = ft_strlen(map[row + 1]);
	while (map[++row] != NULL)
	{
		currentrow = ft_strlen(map[row]);
		column = -1;
		while (map[row][++column])
		{
			c = map[row][column];
			if (((row == 0 || map[row + 1] == NULL || column == 0
						|| column == currentrow - 1) && (c != '1'))
				|| ((c != '0') && (c != '1') && (c != 'E')
					&& (c != 'C') && (c != 'P'))
				|| previousrow != currentrow)
				exitmap(map, 1);
		}
		previousrow = ft_strlen(map[row]);
	}
	checkcount(map);
}

int	checkwall(t_game *game, t_character *character, int direction, char c)
{
	int		x;
	int		y;
	int		modx;
	int		mody;
	char	**map;

	x = character->positonx / game->size;
	y = character->positony / game->size;
	modx = (character->positonx % game->size);
	mody = (character->positony % game->size);
	map = game->map;
	if (direction == LEFT && (!modx
			&& ((mody && map[y + 1][x - 1] == c) || map[y][x - 1] == c)))
		return (1);
	if (direction == RIGHT && (!modx
			&& ((mody && map[y + 1][x + 1] == c) || map[y][x + 1] == c)))
		return (1);
	if (direction == UP && (!mody
			&& ((modx && map[y - 1][x + 1] == c) || map[y - 1][x] == c)))
		return (1);
	if (direction == DOWN && (!mody
			&& ((modx && map[y + 1][x + 1] == c) || map[y + 1][x] == c)))
		return (1);
	return (0);
}

void	checkname(char *arg)
{
	char	*ptr;
	int		len1;
	int		len2;
	int		fd;

	fd = open(arg, O_RDONLY);
	close(fd);
	if (!fd)
		return ;
	ptr = ".ber";
	len1 = ft_strlen(arg) - 1;
	len2 = ft_strlen(ptr) - 1;
	while (len2 >= 0 && len1 >= 0)
	{
		if (arg[len1--] != ptr[len2--])
			error();
	}
}
