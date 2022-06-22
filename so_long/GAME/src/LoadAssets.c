/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoadAssets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:21:16 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 18:36:47 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*load_image(t_game *game, const char *p, int c)
{
	void	*newimage;
	char	*ptr;
	int		width;
	int		height;
	char	index[2];

	index[0] = '0' + c;
	index[1] = '\0';
	ptr = ft_strjoin(ft_strjoin(ft_strdup(p), index), ".xpm");
	newimage = mlx_xpm_file_to_image(game->mlx, ptr, &width, &height);
	free(ptr);
	return (newimage);
}
