/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:35:25 by grudler           #+#    #+#             */
/*   Updated: 2019/09/05 15:27:51 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void		put_pixel_to_img(t_mlx *mlx, int color, int x, int y)
{
	if (x < WINALL && y < WINY)
		*(int *)&mlx->i.canvas[y * mlx->i.size_line + x * 4] = color;
}

void		decalage_palette(t_mlx *mlx)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = mlx->clr.palette[0];
	while (i < 15)
	{
		mlx->clr.palette[i] = mlx->clr.palette[i + 1];
		i++;
	}
	mlx->clr.palette[i] = tmp;
	mlx->clr.j = 1;
}
