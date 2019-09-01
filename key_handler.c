/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:12:43 by grudler           #+#    #+#             */
/*   Updated: 2019/09/01 23:41:23 by grudler          ###   ########.fr       */
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
	if ((mlx->keyboard[KEY_LEFT] && !mlx->keyboard[KEY_RIGHT]) 
		|| (mlx->keyboard[KEY_RIGHT] && !mlx->keyboard[KEY_LEFT]))
		mlx->al.x1 += mlx->keyboard[KEY_LEFT] ? 10 / mlx->al.zoom: -10 
			/ mlx->al.zoom;
	if ((mlx->keyboard[KEY_DOWN] && !mlx->keyboard[KEY_UP]) 
		|| (mlx->keyboard[KEY_UP] && !mlx->keyboard[KEY_DOWN]))
		mlx->al.y1 += mlx->keyboard[KEY_UP] ? 10 / mlx->al.zoom: -10 
			/ mlx->al.zoom;
	if (mlx->keyboard[KEY_SPACEBAR])
		init_var(mlx);
	if (mlx->keyboard[KEY_I])
		mlx->al.it_max += 10;
	if (mlx->keyboard[KEY_O] && mlx->al.it_max > 10)
		mlx->al.it_max -= 10;
	if (mlx->keyboard[KEY_D] && mlx->clr.end <= 200)
		mlx->clr.end += 1;
	if (mlx->keyboard[KEY_F] && mlx->clr.end >= 0)
		mlx->clr.end -= 1;
}

