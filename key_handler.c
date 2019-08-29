/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:12:43 by grudler           #+#    #+#             */
/*   Updated: 2019/08/29 17:08:28 by grudler          ###   ########.fr       */
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

int			mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	pmlx->mousebutton = button;
	pmlx->mousex = x;
	pmlx->mousey = y;
	pmlx->mouseboard[button] = 1;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	pmlx->mousex = x;
	pmlx->mousey = y;
	pmlx->mouseboard[button] = 0;
	pmlx->mousebutton = 0;
	return (0);
}

void		mouse_hook(t_mlx *mlx)
{
	if (mlx->mouseboard[mlx->mousebutton] && mlx->mousebutton == 1 && mlx->mousex < WINX)
	{
		mlx->x1 = (mlx->mousex / mlx->zoom + mlx->x1) - (mlx->mousex / (mlx->zoom * 1.3	));
		mlx->y1 = (mlx->mousey / mlx->zoom + mlx->y1) - (mlx->mousey / (mlx->zoom * 1.3));
		mlx->zoom = mlx->zoom * 1.3;
		mlx->it_max++;
	}
	if (mlx->mouseboard[mlx->mousebutton] && mlx->mousebutton == 2 && mlx->mousex < WINX)
	{
		mlx->x1 = (mlx->mousex / mlx->zoom + mlx->x1) - (mlx->mousex / (mlx->zoom / 1.3));
		mlx->y1 = (mlx->mousey / mlx->zoom + mlx->y1) - (mlx->mousey / (mlx->zoom / 1.3));
		mlx->zoom = mlx->zoom / 1.3;
		mlx->it_max--;
	}
	if (mlx->mousex > 1155 && mlx->mousey > 467 && mlx->mousex < 1190 && mlx->mousey < 492 && mlx->chgcolor != 2)
		mlx->chgcolor++;
	else if (mlx->mousex > 1155 && mlx->mousey > 467 && mlx->mousex < 1190 && mlx->mousey < 492)
		mlx->chgcolor = 0;
	if (mlx->mousex > 800 && mlx->mousey < 150 && mlx->fract != 2 && mlx->mousey != 0)
	{
		mlx->fract++;
		init_var(mlx);
	}
	else if (mlx->mousex > 800 && mlx->mousey < 150 && mlx->mousey != 0)
	{
		mlx->fract = 0;
		init_var(mlx);
	}
	mlx->mousex = 0;
	mlx->mousey = 0;
}
