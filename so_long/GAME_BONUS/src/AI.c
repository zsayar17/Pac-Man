/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:02:48 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 04:31:53 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	attemptmove(t_game *game, int *ex, int *ey, int direction)
{
	if (direction == LEFT)
		*ex -= game->size;
	else if (direction == RIGHT)
		*ex += game->size;
	else if (direction == UP)
		*ey -= game->size;
	else if (direction == DOWN)
		*ey += game->size;
}

void	target(t_game *game, int *ex, int *ey, int ghost)
{
	int	value;

	if (ghost == BLINKY || ghost == CLYDE)
		value = 0;
	else if (ghost == PINKY)
		value = 4;
	else if (ghost == TINKY)
		value = 2;
	if (game->character->movedirection == LEFT)
		*ex += -value * game->size;
	else if (game->character->movedirection == RIGHT)
		*ex += value * game->size;
	else if (game->character->movedirection == UP)
	{
		*ey += -value * game->size;
		*ex += -value * game->size;
	}
	else if (game->character->movedirection == DOWN)
		*ey += value * game->size;
}

int	distance(t_game *game, t_character *e, int direction, int ghost)
{
	int			dy;
	int			dx;
	int			ex;
	int			ey;
	t_character	*c;

	c = game->character;
	if (ghost == TINKY)
		e = game->enemy[0];
	ex = e->positonx;
	ey = e->positony;
	attemptmove(game, &ex, &ey, direction);
	target(game, &ex, &ey, ghost);
	dy = (ey - c->positony) / game->size;
	dx = (ex - c->positonx) / game->size;
	if (ghost == CLYDE && (ft_pow(abs(dy), 2) + ft_pow(abs(dx), 2)) < 16)
	{
		dy = (ey - (game->mapsizey * game->size)) / game->size;
		dx = ex / game->size;
	}
	if (ghost == TINKY)
		return ((ft_pow(abs(dy), 2) + ft_pow(abs(dx), 2)) * 4);
	return (ft_pow(abs(dy), 2) + ft_pow(abs(dx), 2));
}

void	ai_algorithm(t_game *game, t_character *e, int type, int ghost)
{
	int	dir[4];

	if (type == CATCH)
		fillmax(&dir[0], &dir[1], &dir[2], &dir[3]);
	else if (type == ESCAPE)
	{
		fillmin(&dir[0], &dir[1], &dir[2], &dir[3]);
		ghost = BLINKY;
	}
	if (!(e->positony % game->size) && !(e->positonx % game->size))
	{
		if (!checkwall(game, e, RIGHT, '1') && LEFT != e->moveattempt)
			dir[0] = distance(game, e, RIGHT, ghost);
		if (!checkwall(game, e, LEFT, '1') && RIGHT != e->moveattempt)
			dir[1] = distance(game, e, LEFT, ghost);
		if (!checkwall(game, e, DOWN, '1') && UP != e->moveattempt)
			dir[2] = distance(game, e, DOWN, ghost);
		if (!checkwall(game, e, UP, '1') && DOWN != e->moveattempt)
			dir[3] = distance(game, e, UP, ghost);
		if (type == CATCH)
			e->movedirection = findmin(dir[0], dir[1], dir[2], dir[3]);
		else if (type == ESCAPE)
			e->movedirection = findmax(dir[0], dir[1], dir[2], dir[3]);
		e->moveattempt = e->movedirection;
	}
}
