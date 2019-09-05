/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:58:18 by grudler           #+#    #+#             */
/*   Updated: 2019/09/05 11:47:14 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

double		get_percent(int start, int end, int current)
{
	double	pos;
	double	distance;

	pos = current - start;
	distance = end - start;
	return (distance == 0 ? 1.0 : pos / distance);
}

double		get_light(int start, int end, double percent)
{
	return ((1 - percent) * start + percent * end);
}

int			get_color(t_mlx *mlx)
{
	int			red;
	int			green;
	int			blue;
	double		percent;

	percent = get_percent(0, mlx->clr.end, mlx->a.it);
	red = get_light((mlx->clr.color >> 16) & 0xFF, (0xFFFFFF >> 16) & 0xFF,
		percent);
	green = get_light((mlx->clr.color >> 8) & 0xFF, (0xFFFFFF >> 8) & 0xFF,
		percent);
	blue = get_light((mlx->clr.color) & 0xFF, (0xFFFFFF) & 0xFF, percent);
	return ((red << 16) | green << 8 | blue);
}
