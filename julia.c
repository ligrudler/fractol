/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:23:06 by grudler           #+#    #+#             */
/*   Updated: 2019/08/30 22:41:29 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_calc(t_mlx *pmlx)
{
	double tmp;

	pmlx->al.c_r = -0.74543;
	pmlx->al.c_i = 0.11301;
	pmlx->al.z_r = pmlx->al.x / pmlx->al.zoom + pmlx->al.x1;
	pmlx->al.z_i = pmlx->al.y / pmlx->al.zoom + pmlx->al.y1;
	pmlx->al.it = 0;
	while (pmlx->al.z_r * pmlx->al.z_r + pmlx->al.z_i * pmlx->al.z_i < 4 
		&& pmlx->al.it < pmlx->al.it_max)
	{
		tmp = pmlx->al.z_r;
		pmlx->al.z_r = pmlx->al.z_r * pmlx->al.z_r - pmlx->al.z_i 
			* pmlx->al.z_i + pmlx->al.c_r + (pmlx->m.j_x / (WINX / 2) )- 1;
		pmlx->al.z_i = 2 * pmlx->al.z_i * tmp + pmlx->al.c_i + (pmlx->m.j_y / (WINY / 2)) - 1;
		pmlx->al.it++;
	}
}

void		*julia(void *param)
{
	t_mlx		*pmlx;

	pmlx = (t_mlx *)param;
	while(pmlx->al.x++ < WINX)
	{
		pmlx->al.y = 0;
		while (pmlx->al.y++ < WINY)
		{
			julia_calc(pmlx);
			if (pmlx->al.it >= pmlx->al.it_max)
				put_pixel_to_img(pmlx, 0x000000);
			else 
				put_pixel_to_img(pmlx, pmlx->clr.palette[pmlx->al.it % 16]);
		}
	}
	return (param);
}
