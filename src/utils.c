/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:35:25 by grudler           #+#    #+#             */
/*   Updated: 2019/10/15 15:16:20 by lgrudler         ###   ########.fr       */
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

void		clean_mlx(t_mlx *mlx, int idx)
{
	if (mlx->i.img)
		mlx_destroy_image(mlx->ptr, mlx->i.img);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	if (idx == 0)
		ft_putstr("Error\n");
	if (idx == 2)
		ft_putstr("Error thread create\n");
	exit(0);
}
