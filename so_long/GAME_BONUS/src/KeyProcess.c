/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyProcess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:13:05 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 20:48:35 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	keyprocessing(int keyevent, t_game *game)
{
	if (keyevent == ESC)
		exitgame(game);
	else if (keyevent == W)
		game->character->moveattempt = UP;
	else if (keyevent == A)
		game->character->moveattempt = LEFT;
	else if (keyevent == D)
		game->character->moveattempt = RIGHT;
	else if (keyevent == S)
		game->character->moveattempt = DOWN;
	return (1);
}

int	destroy(t_game *game)
{
	exitgame(game);
	return (1);
}
