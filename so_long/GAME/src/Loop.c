/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:24:04 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/22 08:39:39 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update(t_game *game)
{
	updatedirection(game->character);
	movecharacter(game);
	collectables(game);
}

void	draw(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	draw_map(game, game->map);
	draw_character(game->mlx, game->window, game->character);
}

int	loop(t_game *game)
{
	update(game);
	usleep(10000);
	draw(game);
	usleep(10000);
	return (1);
}
