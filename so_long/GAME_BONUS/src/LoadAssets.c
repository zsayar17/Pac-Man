/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoadAssets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:21:16 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 06:42:17 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_image	*load_image(t_game *game, const char *p, const char *c, int num)
{
	t_image	*newimage;
	char	*ptr;
	int		width;
	int		height;
	char	index[3];

	if (num >= 10)
	{
		index[0] = '0' + (num / 10);
		index[1] = '0' + (num % 10);
		index[2] = '\0';
	}
	else
	{
		index[0] = '0' + num;
		index[1] = '\0';
		index[2] = '\0';
	}
	newimage = (t_image *)malloc(sizeof(t_image));
	ptr = ft_strjoin(ft_strjoin(ft_strjoin(ft_strdup(p), c), index), ".xpm");
	newimage->image = mlx_xpm_file_to_image(game->mlx, ptr, &width, &height);
	free(ptr);
	return (newimage);
}

t_image	*load_assets(t_game *game, const char *p, const char *c, int count)
{
	t_image		*first;
	t_image		*begin;
	int			index;

	index = 0;
	first = load_image(game, p, c, index + 1);
	begin = first;
	while (++index < count)
	{
		begin->next = load_image(game, p, c, index + 1);
		begin = begin->next;
	}
	if (count < 10)
		begin->next = first;
	else
		begin->next = NULL;
	return (first);
}
