/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:23:06 by grudler           #+#    #+#             */
/*   Updated: 2019/08/28 11:57:35 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_calc(t_mlx *pmlx)
{
	double tmp;

	pmlx->c_r = -0.74543;
	pmlx->c_i = 0.11301;
	pmlx->z_r = pmlx->x / pmlx->zoom + pmlx->x1;
	pmlx->z_i = pmlx->y / pmlx->zoom + pmlx->y1;
	pmlx->it = 0;
	while (pmlx->z_r * pmlx->z_r + pmlx->z_i * pmlx->z_i < 4 && pmlx->it < pmlx->it_max)
	{
		tmp = pmlx->z_r;
		pmlx->z_r = pmlx->z_r * pmlx->z_r - pmlx->z_i * pmlx->z_i + pmlx->c_r;
		pmlx->z_i = 2 * pmlx->z_i * tmp + pmlx->c_i;
		pmlx->it++;
	}
}

void		*julia(void *param)
{
	t_mlx		*pmlx;

	pmlx = (t_mlx *)param;
	while(pmlx->x < WINX)
	{
		pmlx->y = 0;
		while (pmlx->y < WINY)
		{
			julia_calc(pmlx);
			if (pmlx->it >= pmlx->it_max)
				put_pixel_to_img(pmlx, 0x000000);
			else 
				put_pixel_to_img(pmlx, pmlx->palette[pmlx->it % 16]);
			pmlx->y++;
		}
		pmlx->x++;
	}
	return (param);
}
