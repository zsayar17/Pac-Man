/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:44:53 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 20:21:16 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INFO_H
# define GAME_INFO_H

# include "objects.h"
# include "../../mlx/mlx.h"

# define LEFT -3
# define RIGHT -1
# define UP 1
# define DOWN 3
# define WAIT 0
# define PANIC 4
# define MOVESPEED 4
# define ANIMATIONSPEED 1
# define CATCH 1
# define ESCAPE 0
# define DIED 1
# define ALIVE 0

typedef struct s_game
{
	char				**map;
	void				*mlx;
	void				*window;
	t_static_objects	*staticobjects;
	t_character			*character;
	t_character			**enemy;
	int					iscatch;
	int					mapsizex;
	int					mapsizey;
	int					size;
	int					score;
	int					stepcount;
	int					delimeter;
	int					coincount;
	int					enemycount;
}	t_game;

#endif
