/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:12:43 by grudler           #+#    #+#             */
/*   Updated: 2019/08/22 14:21:38 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int key, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	pmlx->keyboard[key] = 1;
	return (0);
}

int		key_release(int key, void *param)
{
	t_mlx *pmlx;

	pmlx = (t_mlx *)param;
	pmlx->keyboard[key] = 0;
	return (0);
}

void	init_key(t_mlx *mlx)
{
	if (mlx->keyboard[KEY_ESCAPE])
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	if (mlx->keyboard[KEY_O])
		mlx->zoom = mlx->zoom + 10;
	if (mlx->keyboard[KEY_P])
		mlx->zoom = mlx->zoom - 10;
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	if (button == 1)
	{
		pmlx->x1 = (x / pmlx->zoom + pmlx->x1) - (x / (pmlx->zoom * 1.3));
		pmlx->y1 = (y / pmlx->zoom + pmlx->y1) - (y / (pmlx->zoom * 1.3));
		pmlx->zoom = pmlx->zoom * 1.3;
		pmlx->it_max++;
	}
	if (button == 2)
	{
		pmlx->x1 = (x / pmlx->zoom + pmlx->x1) - (x / (pmlx->zoom / 1.3));
		pmlx->y1 = (y / pmlx->zoom + pmlx->y1) - (y / (pmlx->zoom / 1.3));
		pmlx->zoom = pmlx->zoom / 1.3;
		pmlx->it_max--;
	}
	return (0);
}