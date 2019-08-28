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

void	init_var_julia(t_mlx *pmlx)
{
	pmlx->x = 0;
	pmlx->y = 0;
	pmlx->x1 = -1.7;
	pmlx->y1 = -1.4;
	pmlx->it_max = 300;
	pmlx->color = 265;
	pmlx->zoom = 300;
}

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
				put_pixel(pmlx, 0x000000, pmlx->x, pmlx->y);
			else 
				put_pixel(pmlx, pmlx->color, pmlx->x, pmlx->y);
			pmlx->y++;
		}
		pmlx->x++;
	}
	return (param);
}

int			julia_thread(t_mlx *pmlx)
{
	t_mlx		tab[NBR_THREAD];
	pthread_t	t[NBR_THREAD];
	int			i;

	i = 0;
	ft_bzero(pmlx->canvas, WINX * WINY * 4);
	init_key(pmlx);
	while (i < NBR_THREAD)
	{
		ft_memcpy((void *)&tab[i], (void *)pmlx, sizeof(t_mlx));
		tab[i].y = WIN_THREAD * i;
		tab[i].y_max = WIN_THREAD * (i + 1);
		if (pthread_create(&t[i], NULL, julia, &tab[i]))
			ft_error();
		i ++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, 0, 0);
	return (0);
}