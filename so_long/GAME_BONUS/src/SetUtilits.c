/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetUtilits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:40:20 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 14:43:52 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strdup(const char *dest)
{
	char	*ptr;
	char	*holderptr;

	if (dest == NULL || *dest == 0)
		return (NULL);
	ptr = (char *)malloc((sizeof(char) * ft_strlen(dest)) + 1);
	holderptr = ptr;
	while (*dest)
		*(ptr++) = *(dest++);
	*ptr = 0;
	return (holderptr);
}

char	*ft_strjoin(char *dest, const char *src)
{
	char	*ptr;
	char	*holderptr;
	char	*destholder;
	int		lendest;
	int		lensrc;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (dest == NULL && src == NULL)
		return (NULL);
	ptr = (char *)malloc((sizeof(char) * (lendest + lensrc)) + 1);
	holderptr = ptr;
	destholder = dest;
	while (dest != NULL && *dest)
		*(ptr++) = *(dest++);
	while (src != NULL && *src)
		*(ptr++) = *(src++);
	*ptr = 0;
	if (destholder != NULL)
		free (destholder);
	return (holderptr);
}

char	**add_line(char **ptr, char *line)
{
	char	**newptr;
	int		i;

	i = -1;
	if (ptr == NULL)
	{
		newptr = (char **)malloc(sizeof(char *) * 2);
		newptr[++i] = line;
		newptr[++i] = NULL;
		return (newptr);
	}
	newptr = (char **)malloc(sizeof(char *) * (linelen(ptr) + 2));
	while (ptr[++i] != NULL)
		newptr[i] = ptr[i];
	newptr[i++] = line;
	newptr[i] = NULL;
	free(ptr);
	return (newptr);
}

t_character	**add_character(t_character **character, t_character *line)
{
	t_character	**newc;
	int			i;
	int			lenc;

	i = -1;
	if (character == NULL)
	{
		newc = (t_character **)malloc(sizeof(t_character *) * 2);
		newc[++i] = line;
		newc[++i] = NULL;
		return (newc);
	}
	lenc = characterlen(character);
	newc = (t_character **)malloc(sizeof(t_character *) * (lenc + 2));
	while (character[++i] != NULL)
		newc[i] = character[i];
	newc[i++] = line;
	newc[i] = NULL;
	free(character);
	return (newc);
}
