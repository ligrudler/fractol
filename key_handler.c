/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:12:43 by grudler           #+#    #+#             */
/*   Updated: 2019/08/28 11:43:14 by grudler          ###   ########.fr       */
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
	{
		if (mlx->fract == 0)
			init_var(mlx);
		if (mlx->fract == 1)
			init_var_julia(mlx);
		if (mlx->fract == 2)
			init_var_burning(mlx);
	}
	/*if (mlx->keyboard[KEY_Z])
	{
		printf("%d\n", mlx->chgcolor);
	//	mlx->chgcolor -= 1 ? -1 : mlx->chgcolor;
		if (mlx->chgcolor == 1)
			mlx->chgcolor = 0;
		else
			mlx->chgcolor++;
	}*/
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	if (button == 1 && x < WINX)
	{
		pmlx->x1 = (x / pmlx->zoom + pmlx->x1) - (x / (pmlx->zoom * 1.3	));
		pmlx->y1 = (y / pmlx->zoom + pmlx->y1) - (y / (pmlx->zoom * 1.3));
		pmlx->zoom = pmlx->zoom * 1.3;
		pmlx->it_max++;
	}
	if (button == 2 && x < WINX)
	{
		pmlx->x1 = (x / pmlx->zoom + pmlx->x1) - (x / (pmlx->zoom / 1.3));
		pmlx->y1 = (y / pmlx->zoom + pmlx->y1) - (y / (pmlx->zoom / 1.3));
		pmlx->zoom = pmlx->zoom / 1.3;
		pmlx->it_max--;
	}
	if (x > 1155 && y > 467 && x < 1190 && y < 492 && pmlx->chgcolor != 1)
		pmlx->chgcolor++;
	else if (x > 1155 && y > 467 && x < 1190 && y < 492)
		pmlx->chgcolor = 0;
	return (0);
}