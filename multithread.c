
#include "fractol.h"

void	init_var(t_mlx *pmlx)
{
	pmlx->x = 0;
	pmlx->y = 0;
	pmlx->chgcolor = 0;
	pmlx->it_max = 300;
	pmlx->zoom = 250;
	if (pmlx->fract == 0)
	{
		pmlx->x1 = -2.1;
		pmlx->y1 = -1.5;
	}
	if (pmlx->fract == 1)
	{
		pmlx->x1 = -1.6;
		pmlx->y1 = -1.6;
	}
	if (pmlx->fract == 2)
	{
		pmlx->x1 = -2.0;
		pmlx->y1 = -1.8;
	}
}

int		multi_thread(t_mlx *pmlx)
{
	t_mlx		tab[NBR_THREAD];
	pthread_t	t[NBR_THREAD];
	int			i;

	i = 0;
	ft_bzero(pmlx->canvas, WINX * WINY * 4);
	init_key(pmlx);
	mouse_hook(pmlx);
	fill_palette(pmlx);
	while (i < NBR_THREAD)
	{
		ft_memcpy((void *)&tab[i], (void *)pmlx, sizeof(t_mlx));
		tab[i].y = WIN_THREAD * i;
		tab[i].y_max = WIN_THREAD * (i + 1);
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
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, 0, 0);
	return (0);
}