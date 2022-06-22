/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveUtilits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:03:18 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 18:51:15 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	updatenextmove(t_game *game, t_character *character)
{
	int	mattempt;
	int	modx;
	int	mody;
	int	previousmove;

	mattempt = character->moveattempt;
	modx = (game->character->positonx % game->size);
	mody = (game->character->positony % game->size);
	previousmove = character->movedirection;
	if (mattempt > WAIT
		&& !modx && !checkwall(game, character, mattempt, '1'))
		character->movedirection = mattempt;
	else if (mattempt < WAIT
		&& !mody && !checkwall(game, character, mattempt, '1'))
		character->movedirection = mattempt;
	if (previousmove != character->movedirection)
	{
		game->stepcount++;
		write_stepcount(game);
	}
}

void	updatepos(t_game *game, t_character *character, int speed)
{
	if (character->movedirection > WAIT
		&& !checkwall(game, character, character->movedirection, '1'))
		character->positony += (character->movedirection - 2) * speed;
	else if (character->movedirection < WAIT
		&& !checkwall(game, character, character->movedirection, '1'))
		character->positonx += (character->movedirection + 2) * speed;
	else
		character->movedirection = WAIT;
}
