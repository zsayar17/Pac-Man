/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:47:47 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/22 08:46:58 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define PACMAN_DOWN_ASSETPATH "./sprites/Pac-Man/pac_down"
# define PACMAN_UP_ASSETPATH "./sprites/Pac-Man/pac_up"
# define PACMAN_RIGHT_ASSETPATH "./sprites/Pac-Man/pac_right"
# define PACMAN_LEFT_ASSETPATH "./sprites/Pac-Man/pac_left"
# define PACMAN_CLOSED_ASSETPATH "./sprites/Pac-Man/pac_closed"
# define PACMAN_DIED_ASSETPATH "./sprites/Pac-Man/Dying/pacman_dying"
# define GHOST_DOWN_ASSETPATH "./sprites/Ghosts/ghost_down"
# define GHOST_UP_ASSETPATH "./sprites/Ghosts/ghost_up"
# define GHOST_RIGHT_ASSETPATH "./sprites/Ghosts/ghost_right"
# define GHOST_LEFT_ASSETPATH "./sprites/Ghosts/ghost_left"
# define GHOST_PANIC_ASSETPATH "./sprites/Ghosts/Panic/ghost_panic"
# define WALL_ASSETPATH "./sprites/Other/Walls/wall"
# define PORTAL_ASSETPATH "./sprites/Other/Portal/portal"
# define COIN_ASSETPATH "./sprites/Other/Pacdots/pacdot_food"
# define POWERUP_ASSETPATH "./sprites/Other/Pacdots/pacdot_powerup"
# define NUMBERS_ASSETPATH "./sprites/Other/Fonts/"
# define BLUE "B"
# define PINK "K"
# define ORANGE "O"
# define PURPLE "P"
# define RED "R"
# define YELLOW "Y"
# define BLINKY 1
# define PINKY 2
# define TINKY 3
# define CLYDE 4

typedef struct s_image
{
	void				*image;
	struct s_image		*next;
}	t_image;
typedef struct s_static_objects
{
	t_image				*wall;
	t_image				*portal;
	t_image				*coin;
	t_image				*powerup;
	t_image				*numbers;

}	t_static_objects;
typedef struct s_character
{
	t_image				*left;
	t_image				*right;
	t_image				*up;
	t_image				*down;
	t_image				*closed;
	t_image				*panic;
	t_image				**current;
	int					firstposx;
	int					firstposy;
	int					positonx;
	int					positony;
	int					moveattempt;
	int					movedirection;
	int					isdied;
	int					iscatch;
}	t_character;

#endif
