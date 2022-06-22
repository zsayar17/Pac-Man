/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:15:48 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 20:18:56 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	freemap(char **map, int iserror)
{
	int		i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
			free(map[i++]);
		free(map);
	}
	if (iserror)
		error();
}

void	freeimage(t_game *game, t_image *t)
{
	t_image	*temp;
	t_image	*first;

	if (!t)
		return ;
	temp = t;
	first = t;
	while (1)
	{
		if (t->image)
			mlx_destroy_image(game->mlx, t->image);
		if (t->next != NULL && t->next != first)
		{
			temp = t;
			t = t->next;
			free(temp);
		}
		else
			break ;
	}
	free(t);
}

void	freecharacter(t_game *game, t_character *character)
{
	if (!character)
		return ;
	freeimage(game, character->left);
	freeimage(game, character->right);
	freeimage(game, character->up);
	freeimage(game, character->down);
	freeimage(game, character->panic);
	freeimage(game, character->closed);
	free(character);
}

void	freeenemy(t_game *game, t_character **enemy)
{
	int	i;

	if (!enemy)
		return ;
	i = -1;
	while (++i < game->enemycount)
		freecharacter(game, game->enemy[i]);
	free(enemy);
}

void	freestatics(t_game *game, t_static_objects *object)
{
	if (!object)
		return ;
	freeimage(game, object->coin);
	freeimage(game, object->wall);
	freeimage(game, object->numbers);
	freeimage(game, object->portal);
	freeimage(game, object->powerup);
	free(object);
}
