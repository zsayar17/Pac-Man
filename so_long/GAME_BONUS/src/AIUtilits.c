/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AIUtilits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:32:33 by aozsayar          #+#    #+#             */
/*   Updated: 2022/06/21 01:32:36 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	findmax(int r, int l, int d, int u)
{
	if (u >= l && u >= d && u >= r)
		return (UP);
	else if (l >= r && l >= d && l >= u)
		return (LEFT);
	else if (d >= l && d >= r && d >= u)
		return (DOWN);
	else if (r >= l && r >= d && r >= u)
		return (RIGHT);
	return (UP);
}

int	findmin(int r, int l, int d, int u)
{
	if (u <= l && u <= d && u <= r)
		return (UP);
	else if (l <= r && l <= d && l <= u)
		return (LEFT);
	else if (d <= l && d <= r && d <= u)
		return (DOWN);
	else if (r <= l && r <= d && r <= u)
		return (RIGHT);
	return (UP);
}

void	fillmin(int *a, int *b, int *c, int *d)
{
	*a = INT32_MIN;
	*b = INT32_MIN;
	*c = INT32_MIN;
	*d = INT32_MIN;
}

void	fillmax(int *a, int *b, int *c, int *d)
{
	*a = INT32_MAX;
	*b = INT32_MAX;
	*c = INT32_MAX;
	*d = INT32_MAX;
}
