/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:28:26 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/22 08:40:33 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*line(int fd)
{
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = (char *)malloc(sizeof(char) * 2);
	if (buffer == NULL)
		return (NULL);
	while (read(fd, buffer, 1))
	{
		buffer[1] = 0;
		if (*buffer == '\n' || *buffer == 0)
			break ;
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*gettline(char *path)
{
	static int	fd;

	if (!fd)
	{
		fd = open(path, O_RDONLY);
		if (fd <= 0)
			return (NULL);
	}
	return (line(fd));
}

char	**get_map_dataa(char *path)
{
	char		**map;
	char		*line;

	map = NULL;
	while (1)
	{
		line = gettline(path);
		if (line == NULL)
			break ;
		map = add_line(map, line);
	}
	if (map == NULL)
		exitmap(map, 1);
	check_map(map);
	return (map);
}
