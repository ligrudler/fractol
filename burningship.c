/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 22:59:01 by grudler           #+#    #+#             */
/*   Updated: 2019/09/02 12:41:48 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_calc(t_mlx *pmlx)
{
	pmlx->a.c_r = pmlx->a.x / pmlx->a.zoom + pmlx->a.x1;
	pmlx->a.c_i = pmlx->a.y / pmlx->a.zoom + pmlx->a.y1;
	pmlx->a.z_r = 0;
	pmlx->a.z_i = 0;
	pmlx->a.it = 0;
	while (pmlx->a.z_r * pmlx->a.z_r + pmlx->a.z_i * pmlx->a.z_i < 4 
		&& pmlx->a.it < pmlx->a.it_max)
	{
		pmlx->a.temp = pmlx->a.z_r;
		pmlx->a.z_r = pmlx->a.z_r * pmlx->a.z_r - pmlx->a.z_i 
			* pmlx->a.z_i + pmlx->a.c_r;
		pmlx->a.z_i = 2 * fabs(pmlx->a.z_i * pmlx->a.temp) + pmlx->a.c_i;
		pmlx->a.it++;
	}
	if (pmlx->a.it >= pmlx->a.it_max)
		put_pixel_to_img(pmlx, 0x000000, pmlx->a.x, pmlx->a.y);
	else if (pmlx->clr.gradient == 0)
		put_pixel_to_img(pmlx, pmlx->clr.palette[pmlx->a.it % 16], pmlx->a.x, 
			pmlx->a.y);
	else if (pmlx->clr.gradient == 1)
		put_pixel_to_img(pmlx, get_color(pmlx), pmlx->a.x, pmlx->a.y);
}

void		*burning(void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	while (pmlx->a.x < WINX)
	{
		pmlx->a.y = 0;
		while (pmlx->a.y < pmlx->a.y_max)
		{
			burning_calc(pmlx);
			pmlx->a.y++;
		}
		pmlx->a.x++;
	}
	return (param);
}
