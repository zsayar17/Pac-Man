/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveUtilits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:03:18 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 09:09:54 by aozsayar         ###   ########.fr       */
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
		game->stepcount++;
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

void	checkdied(t_character *enemy)
{
	if (enemy->isdied == DIED)
	{
			enemy->positonx = enemy->firstposx;
			enemy->positony = enemy->firstposy;
			enemy->isdied = ALIVE;
			enemy->iscatch = CATCH;
	}
}

void	setalgorithm(t_game *game, t_character *enemy, int index)
{
	if (!(index % 4))
		ai_algorithm(game, enemy, enemy->iscatch, BLINKY);
	else if ((index % 4) == 1)
		ai_algorithm(game, enemy, enemy->iscatch, PINKY);
	else if ((index % 4) == 2)
		ai_algorithm(game, enemy, enemy->iscatch, TINKY);
	else if ((index % 4) == 3)
		ai_algorithm(game, enemy, enemy->iscatch, CLYDE);
}

void	delimeter(t_game *game)
{
	int			index;

	if (game->iscatch == ESCAPE)
	{
		if (game->delimeter++ == 250)
		{
			index = -1;
			while (++index < game->enemycount)
				game->enemy[index]->iscatch = CATCH;
			game->iscatch = CATCH;
			game->delimeter = 0;
		}
	}
}
