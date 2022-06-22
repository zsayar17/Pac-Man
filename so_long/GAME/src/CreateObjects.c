/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateObjects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:52:03 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 19:11:34 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_static_objects	*createobjects(t_game *game)
{
	t_static_objects	*objects;

	objects = (t_static_objects *)malloc(sizeof(t_static_objects));
	objects->wall = load_image(game, WALL_ASSETPATH, 1);
	objects->portal = load_image(game, PORTAL_ASSETPATH, 1);
	objects->coin = load_image(game, COIN_ASSETPATH, 1);
	return (objects);
}

t_character	*createpacman(t_game *game)
{
	t_character	*character;
	int			pos;

	pos = get_character_pos(game->map);
	character = (t_character *)malloc(sizeof(t_character));
	character->down = load_image(game, PACMAN_DOWN_ASSETPATH, 3);
	character->up = load_image(game, PACMAN_UP_ASSETPATH, 3);
	character->left = load_image(game, PACMAN_LEFT_ASSETPATH, 3);
	character->right = load_image(game, PACMAN_RIGHT_ASSETPATH, 3);
	character->closed = load_image(game, PACMAN_CLOSED_ASSETPATH, 1);
	character->current = &(character->up);
	character->positonx = (pos & 255) * game->size;
	character->positony = (pos >> 8) * game->size;
	character->movedirection = WAIT;
	character->moveattempt = WAIT;
	return (character);
}
