/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:41:54 by grudler           #+#    #+#             */
/*   Updated: 2019/09/04 14:50:52 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	mandel_calc(t_mlx *mlx)
{
	mlx->a.c_r = mlx->a.x / mlx->a.zoom + mlx->a.x1;
	mlx->a.c_i = mlx->a.y / mlx->a.zoom + mlx->a.y1;
	mlx->a.z_r = 0;
	mlx->a.z_i = 0;
	mlx->a.it = 0;
	while (mlx->a.z_r * mlx->a.z_r + mlx->a.z_i * mlx->a.z_i < 4
		&& mlx->a.it < mlx->a.it_max)
	{
		mlx->a.temp = mlx->a.z_r;
		mlx->a.z_r = mlx->a.z_r * mlx->a.z_r - mlx->a.z_i * mlx->a.z_i
			+ mlx->a.c_r;
		mlx->a.z_i = 2 * mlx->a.z_i * mlx->a.temp + mlx->a.c_i;
		mlx->a.it++;
	}
	if (mlx->a.it >= mlx->a.it_max)
		put_pixel_to_img(mlx, 0x000000, mlx->a.x, mlx->a.y);
	else if (mlx->clr.gradient == 0)
		put_pixel_to_img(mlx, mlx->clr.palette[mlx->a.it % 16], mlx->a.x,
			mlx->a.y);
	else if (mlx->clr.gradient == 1)
		put_pixel_to_img(mlx, get_color(mlx), mlx->a.x, mlx->a.y);
}

void		*mandelbrot(void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	while (pmlx->a.y++ < pmlx->a.y_max)
	{
		pmlx->a.x = 0;
		while (pmlx->a.x++ < WINX)
			mandel_calc(pmlx);
	}
	return (param);
}
