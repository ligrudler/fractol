/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:41:54 by grudler           #+#    #+#             */
/*   Updated: 2019/07/09 23:20:11 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_var(t_mlx *pmlx)
{
	pmlx->x = 0;
	pmlx->y = 0;
	pmlx->x1 = -2.1;
	pmlx->y1 = -1.2;
	pmlx->it_max = 100;
	pmlx->color = 265;
}

void	mandel_calc(t_mlx *pmlx)
{
	double temp;

	pmlx->c_r = pmlx->x / pmlx->zoom + pmlx->x1;
	pmlx->c_i = pmlx->y / pmlx->zoom + pmlx->y1;
	pmlx->z_r = 0;
	pmlx->z_i = 0;
	pmlx->it = 0;
	while (pmlx->z_r * pmlx->z_r + pmlx->z_i * pmlx->z_i < 4 && pmlx->it < pmlx->it_max)
	{
		temp = pmlx->z_r;
		pmlx->z_r = pmlx->z_r * pmlx->z_r - pmlx->z_i * pmlx->z_i + pmlx->c_r;
		pmlx->z_i = 2 * pmlx->z_i * temp + pmlx->c_i;
		pmlx->it++;
	}
	if (pmlx->it != pmlx->it_max)
		put_pixel(pmlx);
}

int		mandelbrot(void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	init_var(pmlx);
	ft_bzero(pmlx->canvas, WINX * WINY * 4);
	init_key(pmlx);
	while (pmlx->x < WINX)
	{
		pmlx->y = 0;
		while (pmlx->y < WINY)
		{
			mandel_calc(pmlx);
			pmlx->y++;
		}
		pmlx->x++;
	}
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, 0, 0);
	return (0);
	
}