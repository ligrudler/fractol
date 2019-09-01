/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:58:18 by grudler           #+#    #+#             */
/*   Updated: 2019/09/01 18:19:43 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double			get_percent(int start, int end, int current)
{
	double	pos;
	double	distance;

	pos = current - start;
	distance = end - start;
	return (distance == 0 ? 1.0 : pos / distance);
}

double			get_light(int start, int end, double percent)
{
	return ((1 - percent) * start + percent * end);
}
int		get_color(t_mlx *mlx)
{
	int			red;
	int			green;
	int			blue;
	double		percent;

	percent = get_percent(0, 150, mlx->al.it);
	red = get_light((0xFF0000 >> 16) & 0xFF, ( 0xFFFFFF >> 16) & 0xFF, percent);
	green = get_light((0xFF0000 >> 8) & 0xFF, (0xFFFFFF >> 8) & 0xFF, percent);
	blue = get_light((0xFF0000) & 0xFF, (0xFFFFFF) & 0xFF, percent);
	return ((red << 16) | green << 8 | blue);
}
