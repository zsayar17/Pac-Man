/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collactable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:31:43 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 19:24:53 by aozsayar         ###   ########.fr       */
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

void	entry_portal(t_game *game, char *c)
{
	if (*c == 'E' && game->coincount == game->score)
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
		entry_portal(game, &game->map[posy][posx]);
	}
}
