/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:39:48 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 06:19:39 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	updatedirection(t_character *character, int isenemy)
{
	if (character->isdied == DIED && !isenemy)
		character->current = &character->panic;
	else if (character->iscatch == ESCAPE && isenemy)
		character->current = &character->panic;
	else if (character->movedirection == LEFT)
		character->current = &character->left;
	else if (character->movedirection == RIGHT)
		character->current = &character->right;
	else if (character->movedirection == UP)
		character->current = &character->up;
	else if (character->movedirection == DOWN)
		character->current = &character->down;
	else if (character->movedirection == WAIT && !isenemy)
		character->current = &character->closed;
}

void	updateanimation(t_game *game)
{
	static int		delimeter;
	int				i;

	if (delimeter++ == ANIMATIONSPEED)
	{
		if (game->character->movedirection != WAIT
			|| (*game->character->current)->next != NULL)
			*game->character->current = (*game->character->current)->next;
		if (game->enemycount)
		{
			i = -1;
			while (++i < game->enemycount)
			{
				if (game->enemy[i]->movedirection != WAIT)
				{
					*game->enemy[i]->current = (*game->enemy[i]->current)->next;
				}
			}
		}
		delimeter = 0;
	}
}

void	animation(t_game *game)
{
	int	index;

	index = -1;
	updatedirection(game->character, 0);
	while (++index < game->enemycount)
		updatedirection((game->enemy[index]), 1);
	updateanimation(game);
}
