/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:23:06 by grudler           #+#    #+#             */
/*   Updated: 2019/07/09 23:53:57 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_var_julia(t_mlx *pmlx)
{
	pmlx->x = 0;
	pmlx->x1 = -1;
	pmlx->y1 = -1.2;
	pmlx->it_max = 150;
	pmlx->color = 265;
}

int		julia(void *param)
{
	t_mlx		*pmlx;
	double		tmp;

	pmlx = (t_mlx *)param;
	init_var_julia(pmlx);
	ft_bzero(pmlx->canvas, WINX * WINY * 4);
	init_key(pmlx);
	while(pmlx->x < WINX)
	{
		pmlx->y = 0;
		while (pmlx->y < WINY)
		{
			pmlx->c_r = 0.285;
			pmlx->c_i = 0.01;
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
			if (pmlx->it != pmlx->it_max)
				put_pixel(pmlx);
			pmlx->y++;
		}
		pmlx->x++;
	}
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, 0, 0);
	return (0);
}

