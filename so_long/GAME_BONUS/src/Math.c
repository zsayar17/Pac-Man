/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:24:06 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 07:42:29 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_pow(int x, int y)
{
	int	i;

	if (y == 0)
		return (1);
	i = 0;
	while (++i < y)
		x *= x;
	return (x);
}
