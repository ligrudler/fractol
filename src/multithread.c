/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:56 by grudler           #+#    #+#             */
/*   Updated: 2019/10/15 15:15:00 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	first_step(t_mlx *mlx)
{
	ft_bzero(mlx->i.canvas, WINX * WINY * 4);
	init_key(mlx);
	fill_palette(mlx);
	if (mlx->clr.dec == 1)
		decalage_palette(mlx);
}

void	create_thread(t_mlx *pmlx)
{
	t_mlx		tab[NBR_THREAD];
	pthread_t	t[NBR_THREAD];
	int			i;

	i = -1;
	while (++i < NBR_THREAD)
	{
		ft_memcpy((void *)&tab[i], (void *)pmlx, sizeof(t_mlx));
		tab[i].a.y = WIN_THREAD * (i);
		tab[i].a.y_max = WIN_THREAD * (i + 1);
		if (tab[i].fract == 0 && pthread_create(&t[i], NULL, mandelbrot,
			&tab[i]))
			clean_mlx(pmlx, 2);
		else if (tab[i].fract == 1 && pthread_create(&t[i], NULL, julia,
			&tab[i]))
			clean_mlx(pmlx, 2);
		else if (tab[i].fract == 2 && pthread_create(&t[i], NULL, burning,
			&tab[i]))
			clean_mlx(pmlx, 2);
		else if (tab[i].fract == 3 && pthread_create(&t[i], NULL, burningjulia,
			&tab[i]))
			clean_mlx(pmlx, 2);
	}
	while (i--)
		pthread_join(t[i], NULL);
}

int		multi_thread(t_mlx *pmlx)
{
	first_step(pmlx);
	create_thread(pmlx);
	mlx_put_image_to_window(pmlx->ptr, pmlx->win_ptr, pmlx->i.img, 0, 0);
	print_legend(pmlx);
	return (0);
}
