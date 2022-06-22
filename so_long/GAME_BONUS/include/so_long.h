/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:01:31 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 22:50:47 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "game_info.h"

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

int					loop(t_game *game);
void				setup(t_game *game, char *path);
void				update(t_game *game);
void				draw(t_game *game);
t_image				*load_image(t_game *game, const char *p, \
					const char *c, int num);
t_image				*load_assets(t_game *game, const char *p, \
					const char *c, int count);
t_static_objects	*createobjects(t_game *game);
t_character			*createpacman(t_game *game);
t_character			*createenemy(t_game *game, const char *color);
t_character			**createenemies(t_game *game);
void				attemptmove(t_game *game, int *ex, int *ey, int direction);
void				target(t_game *game, int *ex, int *ey, int ghost);
int					distance(t_game *game, t_character *e, \
					int direction, int ghost);
void				ai_algorithm(t_game *game, t_character *e, \
					int type, int ghost);
int					findmax(int r, int l, int d, int u);
int					findmin(int r, int l, int d, int u);
void				fillmin(int *a, int *b, int *c, int *d);
void				fillmax(int *a, int *b, int *c, int *d);
void				updatedirection(t_character *character, int isenemy);
void				updateanimation(t_game *game);
void				animation(t_game *game);
void				checkname(char *arg);
void				checkcount(char **map);
void				check_map(char **map);
int					checkwall(t_game *game, t_character *character, \
					int direction, char c);
int					checkcolission(t_character *e, t_character *c, int size);
void				collect_coin(t_game *game, char *c);
void				collect_powerup(t_game *game, char *c);
void				entry_portal(t_game *game, char *c);
void				collectables(t_game *game);
void				draw_object(t_game *game, void *image, int x, int y);
void				draw_stepcount(t_game *game);
void				draw_map(t_game *game, char **map);
void				draw_character(void *mlx, void *window, \
					t_character *chatacter);
void				draw_enemies(t_game *game);
void				freemap(char **map, int iserror);
void				freeimage(t_game *game, t_image *t);
void				freecharacter(t_game *game, t_character *character);
void				freeenemy(t_game *game, t_character **enemy);
void				freestatics(t_game *game, t_static_objects *object);
void				error(void);
void				exitgame(t_game *game);
size_t				ft_strlen(const char *dest);
size_t				linelen(char **map);
size_t				characterlen(t_character **character);
int					get_character_pos(char **map);
int					get_enemy_pos(char **map);
int					get_object_count(char **map, char c);
const char			*get_color(void);
int					destroy(t_game *game);
int					keyprocessing(int keyevent, t_game *game);
char				*line(int fd);
char				*gettline(char *path);
char				**get_map_dataa(char *path);
int					abs(int a);
int					ft_pow(int x, int y);
void				move_enemies(t_game *game);
void				movecharacter(t_game *game);
void				updatenextmove(t_game *game, t_character *character);
void				updatepos(t_game *game, t_character *character, int speed);
void				checkdied(t_character *enemy);
void				setalgorithm(t_game *game, t_character *enemy, int index);
void				delimeter(t_game *game);
char				*ft_strdup(const char *dest);
char				*ft_strjoin(char *dest, const char *src);
char				**add_line(char **ptr, char *line);
t_character			**add_character(t_character **character, t_character *line);

#endif
