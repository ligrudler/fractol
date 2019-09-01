/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:41:54 by grudler           #+#    #+#             */
/*   Updated: 2019/09/01 20:59:19 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_calc(t_mlx *mlx)
{
	mlx->al.c_r = mlx->al.x / mlx->al.zoom + mlx->al.x1;
	mlx->al.c_i = mlx->al.y / mlx->al.zoom + mlx->al.y1;
	mlx->al.z_r = 0;
	mlx->al.z_i = 0;
	mlx->al.it = 0;
	while (mlx->al.z_r * mlx->al.z_r + mlx->al.z_i * mlx->al.z_i < 4 
		&& mlx->al.it < mlx->al.it_max)
	{
		mlx->al.temp = mlx->al.z_r;
		mlx->al.z_r = mlx->al.z_r * mlx->al.z_r - mlx->al.z_i * mlx->al.z_i 
			+ mlx->al.c_r;
		mlx->al.z_i = 2 * mlx->al.z_i * mlx->al.temp + mlx->al.c_i;
		mlx->al.it++;
	}
	if (mlx->al.it >= mlx->al.it_max)
		put_pixel_to_img(mlx, 0x000000, mlx->al.x, mlx->al.y);
	else if (mlx->clr.gradient == 0)
		put_pixel_to_img(mlx, mlx->clr.palette[mlx->al.it % 16], mlx->al.x, mlx->al.y);
	else if (mlx->clr.gradient == 1)
		put_pixel_to_img(mlx, get_color(mlx), mlx->al.x, mlx->al.y);
}


void		*mandelbrot(void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	while (pmlx->al.x++ < WINX)
	{
		pmlx->al.y = 0;
		while (pmlx->al.y++ < pmlx->al.y_max)
			mandel_calc(pmlx);
	}
	return (param);
}