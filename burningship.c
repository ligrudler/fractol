/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 22:59:01 by grudler           #+#    #+#             */
/*   Updated: 2019/09/01 18:10:27 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_calc(t_mlx *pmlx)
{
	pmlx->al.c_r = pmlx->al.x / pmlx->al.zoom + pmlx->al.x1;
	pmlx->al.c_i = pmlx->al.y / pmlx->al.zoom + pmlx->al.y1;
	pmlx->al.z_r = 0;
	pmlx->al.z_i = 0;
	pmlx->al.it = 0;
	while (pmlx->al.z_r * pmlx->al.z_r + pmlx->al.z_i * pmlx->al.z_i < 4 
		&& pmlx->al.it < pmlx->al.it_max)
	{
		pmlx->al.temp = pmlx->al.z_r;
		pmlx->al.z_r = pmlx->al.z_r * pmlx->al.z_r - pmlx->al.z_i 
			* pmlx->al.z_i + pmlx->al.c_r;
		pmlx->al.z_i = 2 * fabs(pmlx->al.z_i * pmlx->al.temp) + pmlx->al.c_i;
		pmlx->al.it++;
	}
	if (pmlx->al.it >= pmlx->al.it_max)
		put_pixel_to_img(pmlx, 0x000000, pmlx->al.x, pmlx->al.y);
	else if (pmlx->clr.gradient == 0)
		put_pixel_to_img(pmlx, pmlx->clr.palette[pmlx->al.it % 16], pmlx->al.x, pmlx->al.y);
	else if (pmlx->clr.gradient == 1)
		put_pixel_to_img(pmlx, get_color(pmlx), pmlx->al.x, pmlx->al.y);
}

void		*burning(void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	while (pmlx->al.x < WINX)
	{
		pmlx->al.y = 0;
		while (pmlx->al.y < pmlx->al.y_max)
		{
			burning_calc(pmlx);
			pmlx->al.y++;
		}
		pmlx->al.x++;
	}
	return (param);
}
