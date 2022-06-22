/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:47:47 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/22 08:38:11 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define PACMAN_DOWN_ASSETPATH "./sprites/Pac-Man/pac_down"
# define PACMAN_UP_ASSETPATH "./sprites/Pac-Man/pac_up"
# define PACMAN_RIGHT_ASSETPATH "./sprites/Pac-Man/pac_right"
# define PACMAN_LEFT_ASSETPATH "./sprites/Pac-Man/pac_left"
# define PACMAN_CLOSED_ASSETPATH "./sprites/Pac-Man/pac_closed"
# define WALL_ASSETPATH "./sprites/Other/Walls/wall"
# define PORTAL_ASSETPATH "./sprites/Other/Portal/portal"
# define COIN_ASSETPATH "./sprites/Other/Pacdots/pacdot_food"

typedef struct s_static_objects
{
	void				*wall;
	void				*portal;
	void				*coin;

}	t_static_objects;

typedef struct s_character
{
	void				*left;
	void				*right;
	void				*up;
	void				*down;
	void				*closed;
	void				**current;
	int					positonx;
	int					positony;
	int					moveattempt;
	int					movedirection;
}	t_character;

#endif
