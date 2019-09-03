/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:23:06 by grudler           #+#    #+#             */
/*   Updated: 2019/09/03 13:43:58 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_calc(t_mlx *pmlx)
{
	double tmp;

	pmlx->a.c_r = -0.74543;
	pmlx->a.c_i = 0.11301;
	pmlx->a.z_r = pmlx->a.x / pmlx->a.zoom + pmlx->a.x1;
	pmlx->a.z_i = pmlx->a.y / pmlx->a.zoom + pmlx->a.y1;
	pmlx->a.it = 0;
	while (pmlx->a.z_r * pmlx->a.z_r + pmlx->a.z_i * pmlx->a.z_i < 4
		&& pmlx->a.it < pmlx->a.it_max)
	{
		tmp = pmlx->a.z_r;
		pmlx->a.z_r = pmlx->a.z_r * pmlx->a.z_r - pmlx->a.z_i
			* pmlx->a.z_i + pmlx->a.c_r + (pmlx->m.j_x / (WINX / 2) )- 1;
		pmlx->a.z_i = 2 * pmlx->a.z_i * tmp + pmlx->a.c_i + (pmlx->m.j_y
			/ (WINY / 2)) - 1;
		pmlx->a.it++;
	}
}

void		*julia(void *param)
{
	t_mlx		*pmlx;

	pmlx = (t_mlx *)param;
	while(pmlx->a.y++ < pmlx->a.y_max)
	{
		pmlx->a.x = 0;
		while (pmlx->a.x++ < WINX)
		{
			julia_calc(pmlx);
			if (pmlx->a.it >= pmlx->a.it_max)
				put_pixel_to_img(pmlx, 0x000000, pmlx->a.x, pmlx->a.y);
			else if (pmlx->clr.gradient == 0)
				put_pixel_to_img(pmlx, pmlx->clr.palette[pmlx->a.it % 16],
					pmlx->a.x, pmlx->a.y);
			else if (pmlx->clr.gradient == 1)
				put_pixel_to_img(pmlx, get_color(pmlx), pmlx->a.x, pmlx->a.y);
		}
	}
	return (param);
}
