/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collactable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:31:43 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 20:06:28 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collect_coin(t_game *game, char *c)
{
	if (*c != 'C')
		return ;
	*c = '0';
	game->score++;
}

void	collect_powerup(t_game *game, char *c)
{
	int	i;

	if (!(*c == 'E' && game->score != game->coincount))
		return ;
	*c = 'e';
	i = -1;
	while (++i < game->enemycount)
	{
		game->enemy[i]->iscatch = ESCAPE;
		game->enemy[i]->moveattempt = WAIT;
		game->delimeter = 0;
	}
	game->iscatch = ESCAPE;
}

void	entry_portal(t_game *game, char *c)
{
	if ((*c == 'E' || *c == 'e') && game->coincount == game->score)
		exitgame(game);
}

void	collectables(t_game *game)
{
	int	posx;
	int	posy;

	posx = game->character->positonx / game->size;
	posy = game->character->positony / game->size;
	if ((!(game->character->positonx % game->size)
			|| !(game->character->positony % game->size)))
	{
		collect_coin(game, &game->map[posy][posx]);
		collect_powerup(game, &game->map[posy][posx]);
		entry_portal(game, &game->map[posy][posx]);
	}
}
