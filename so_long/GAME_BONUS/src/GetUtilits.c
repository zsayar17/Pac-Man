/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetUtilits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:37:02 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 01:42:06 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strlen(const char *dest)
{
	size_t	counter;

	counter = 0;
	if (dest == NULL)
		return (0);
	while (*(dest++))
		counter++;
	return (counter);
}

size_t	linelen(char **map)
{
	size_t	counter;

	counter = 0;
	while (map[counter] != NULL)
		counter++;
	return (counter);
}

size_t	characterlen(t_character **character)
{
	size_t	counter;

	counter = 0;
	while (character[counter] != NULL)
		counter++;
	return (counter);
}
