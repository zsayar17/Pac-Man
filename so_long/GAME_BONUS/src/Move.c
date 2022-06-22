/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:11:18 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 22:51:02 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_enemies(t_game *game)
{
	int			i;

	i = -1;
	delimeter(game);
	while (++i < game->enemycount)
	{
		checkcolission(game->enemy[i], game->character, game->size);
		checkdied(game->enemy[i]);
		setalgorithm(game, game->enemy[i], i);	
		updatepos(game, game->enemy[i], MOVESPEED);
	}
}

void	movecharacter(t_game *game)
{
	if (game->character->isdied == ALIVE)
	{
		updatenextmove(game, game->character);
		updatepos(game, game->character, MOVESPEED);
	}
	if ((*game->character->current)->next == NULL)
		exitgame(game);
}
