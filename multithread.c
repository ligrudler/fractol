/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:56 by grudler           #+#    #+#             */
/*   Updated: 2019/09/02 00:13:30 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_var(t_mlx *pmlx)
{
	pmlx->al.x = 0;
	pmlx->al.y = 0;
	pmlx->clr.chgcolor = 0;
	pmlx->al.it_max = 100;
	pmlx->al.zoom = ZOOM;
	pmlx->stop = 1;
	pmlx->m.j_x = 400;
	pmlx->m.j_y = 400;
	pmlx->clr.gradient = 0;
	pmlx->clr.end = 15;
	pmlx->clr.m = 0;
	pmlx->clr.color = 0x0000FF;
	if (pmlx->fract == 0)
	{
		pmlx->al.x1 = -2.1;
		pmlx->al.y1 = -1.5;
	}
	if (pmlx->fract == 1)
	{
		pmlx->al.x1 = -1.6;
		pmlx->al.y1 = -1.6;
	}
	if (pmlx->fract == 2)
	{
		pmlx->al.x1 = -2.0;
		pmlx->al.y1 = -2.0;
	}
}

void	first_step(t_mlx *mlx)
{
	ft_bzero(mlx->i.canvas, WINX * WINY * 4);
	init_key(mlx);
	fill_palette(mlx);
}

int		multi_thread(t_mlx *pmlx)
{
	t_mlx		tab[NBR_THREAD];
	pthread_t	t[NBR_THREAD];
	int			i;

	i = 0;
	first_step(pmlx);
	while (i < NBR_THREAD)
	{
		ft_memcpy((void *)&tab[i], (void *)pmlx, sizeof(t_mlx));
		tab[i].al.y = WIN_THREAD * i;
		tab[i].al.y_max = WIN_THREAD * (i + 1);
		if (tab[i].fract == 0)
			pthread_create(&t[i], NULL, mandelbrot, &tab[i]);	/* a proteger ??*/	
		if (tab[i].fract == 1)
			pthread_create(&t[i], NULL, julia, &tab[i]);
		if (tab[i].fract == 2)
			pthread_create(&t[i], NULL, burning, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->i.img, 0, 0);
	print_legend(pmlx);
	return (0);
}