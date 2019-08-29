/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:41:54 by grudler           #+#    #+#             */
/*   Updated: 2019/08/29 23:07:48 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_calc(t_mlx *pmlx)
{
	pmlx->c_r = pmlx->x / pmlx->zoom + pmlx->x1;
	pmlx->c_i = pmlx->y / pmlx->zoom + pmlx->y1;
	pmlx->z_r = 0;
	pmlx->z_i = 0;
	pmlx->it = 0;
	while (pmlx->z_r * pmlx->z_r + pmlx->z_i * pmlx->z_i < 4 && pmlx->it < pmlx->it_max)
	{
		pmlx->temp = pmlx->z_r;
		pmlx->z_r = pmlx->z_r * pmlx->z_r - pmlx->z_i * pmlx->z_i + pmlx->c_r;
		pmlx->z_i = 2 * pmlx->z_i * pmlx->temp + pmlx->c_i;
		pmlx->it++;
	}
	if (pmlx->it >= pmlx->it_max)
		put_pixel_to_img(pmlx, 0x000000);
	else 
		put_pixel_to_img(pmlx, pmlx->clr.palette[pmlx->it % 16]);
}

void		*mandelbrot(void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	while (pmlx->x < WINX)
	{
		pmlx->y = 0;
		while (pmlx->y < pmlx->y_max)
		{
			mandel_calc(pmlx);
			pmlx->y++;
		}
		pmlx->x++;
	}
	return (param);
}