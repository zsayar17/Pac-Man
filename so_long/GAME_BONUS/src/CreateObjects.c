/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateObjects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:52:03 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 20:09:06 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_static_objects	*createobjects(t_game *game)
{
	t_static_objects	*objects;

	objects = (t_static_objects *)malloc(sizeof(t_static_objects));
	objects->wall = load_assets(game, WALL_ASSETPATH, "", 1);
	objects->portal = load_assets(game, PORTAL_ASSETPATH, "", 1);
	objects->coin = load_assets(game, COIN_ASSETPATH, "", 1);
	objects->powerup = load_assets(game, POWERUP_ASSETPATH, "", 1);
	objects->numbers = load_assets(game, NUMBERS_ASSETPATH, "", 10);
	return (objects);
}

t_character	*createpacman(t_game *game)
{
	t_character	*character;
	int			pos;

	pos = get_character_pos(game->map);
	character = (t_character *)malloc(sizeof(t_character));
	character->down = load_assets(game, PACMAN_DOWN_ASSETPATH, "", 4);
	character->up = load_assets(game, PACMAN_UP_ASSETPATH, "", 4);
	character->left = load_assets(game, PACMAN_LEFT_ASSETPATH, "", 4);
	character->right = load_assets(game, PACMAN_RIGHT_ASSETPATH, "", 4);
	character->closed = load_assets(game, PACMAN_CLOSED_ASSETPATH, "", 1);
	character->panic = load_assets(game, PACMAN_DIED_ASSETPATH, "", 11);
	character->current = &(character->closed);
	character->positonx = (pos & 255) * game->size;
	character->firstposx = (pos & 255) * game->size;
	character->positony = (pos >> 8) * game->size;
	character->firstposy = (pos >> 8) * game->size;
	character->movedirection = WAIT;
	character->moveattempt = WAIT;
	character->isdied = ALIVE;
	character->iscatch = CATCH;
	return (character);
}

t_character	*createenemy(t_game *game, const char *color)
{
	t_character	*character;
	int			pos;

	pos = get_enemy_pos(game->map);
	if (!pos)
		return (NULL);
	character = (t_character *)malloc(sizeof(t_character));
	character->down = load_assets(game, GHOST_DOWN_ASSETPATH, color, 2);
	character->up = load_assets(game, GHOST_UP_ASSETPATH, color, 2);
	character->left = load_assets(game, GHOST_LEFT_ASSETPATH, color, 2);
	character->right = load_assets(game, GHOST_RIGHT_ASSETPATH, color, 2);
	character->panic = load_assets(game, GHOST_PANIC_ASSETPATH, "", 4);
	character->closed = NULL;
	character->current = &(character->down);
	character->positonx = (pos & 255) * game->size;
	character->firstposx = (pos & 255) * game->size;
	character->positony = (pos >> 8) * game->size;
	character->firstposy = (pos >> 8) * game->size;
	character->movedirection = WAIT;
	character->moveattempt = WAIT;
	character->isdied = ALIVE;
	character->iscatch = CATCH;
	return (character);
}

t_character	**createenemies(t_game *game)
{
	t_character	**enemies;
	t_character	*newenemy;
	const char	*color;

	enemies = NULL;
	if (!game->enemycount)
		return (NULL);
	while (1)
	{
		color = get_color();
		newenemy = createenemy(game, color);
		if (newenemy == NULL)
			break ;
		enemies = add_character(enemies, newenemy);
	}
	return (enemies);
}
