/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:12:43 by grudler           #+#    #+#             */
/*   Updated: 2019/08/29 17:12:24 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

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
		//mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		//mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr); abort trap 6
		exit(0);
	}
	if ((mlx->keyboard[KEY_LEFT] && !mlx->keyboard[KEY_RIGHT]) || (mlx->keyboard[KEY_RIGHT] && !mlx->keyboard[KEY_LEFT]))
		mlx->x1 += mlx->keyboard[KEY_LEFT] ? 10 / mlx->zoom: -10 / mlx->zoom;
	if ((mlx->keyboard[KEY_DOWN] && !mlx->keyboard[KEY_UP]) || (mlx->keyboard[KEY_UP] && !mlx->keyboard[KEY_DOWN]))
		mlx->y1 += mlx->keyboard[KEY_UP] ? 10 / mlx->zoom: -10 / mlx->zoom;
	if (mlx->keyboard[KEY_SPACEBAR])
		init_var(mlx);
}

