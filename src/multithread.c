/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:56 by grudler           #+#    #+#             */
/*   Updated: 2019/09/04 14:50:56 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/fractol.h"

void	first_step(t_mlx *mlx)
{
	ft_bzero(mlx->i.canvas, WINX * WINY * 4);
	init_key(mlx);
	fill_palette(mlx);
	if (mlx->clr.dec == 1)
		decalage_palette(mlx);
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
		tab[i].a.y = WIN_THREAD * (i);
		tab[i].a.y_max = WIN_THREAD * (i + 1);
		if (tab[i].fract == 0)
			pthread_create(&t[i], NULL, mandelbrot, &tab[i]);
		else if (tab[i].fract == 1)
			pthread_create(&t[i], NULL, julia, &tab[i]);
		else if (tab[i].fract == 2)
			pthread_create(&t[i], NULL, burning, &tab[i]);
		else if (tab[i].fract == 3)
			pthread_create(&t[i], NULL, burningjulia, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->i.img, 0, 0);
	print_legend(pmlx);
	return (0);
}
