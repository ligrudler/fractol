/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:14 by grudler           #+#    #+#             */
/*   Updated: 2019/08/29 23:49:45 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*pmlx;
	
	pmlx = (t_mlx *)param;
	pmlx->m.mousebutton = button;
	pmlx->m.x = x;
	pmlx->m.y = y;
	pmlx->m.mouseboard[button] = 1;
	pmlx->m.tmpx = pmlx->m.x;
	pmlx->m.tmpy = pmlx->m.y;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	pmlx->m.x = x;
	pmlx->m.y = y;
	pmlx->m.mouseboard[button] = 0;
	pmlx->m.tmpx = pmlx->m.x;
	pmlx->m.tmpy = pmlx->m.y;
	return (0);
}

void		zoom_dezoom(t_mlx *mlx)
{
	if (mlx->m.mouseboard[mlx->m.mousebutton] && mlx->m.mousebutton == 1 
		&& mlx->m.x < WINX)
	{
		mlx->al.x1 = (mlx->m.x / mlx->al.zoom + mlx->al.x1) - (mlx->m.x 
			/ (mlx->al.zoom * 1.3));
		mlx->al.y1 = (mlx->m.y / mlx->al.zoom + mlx->al.y1) - (mlx->m.y 
			/ (mlx->al.zoom * 1.3));
		mlx->al.zoom = mlx->al.zoom * 1.3;
		mlx->al.it_max++;
	}
	if (mlx->m.mouseboard[mlx->m.mousebutton] && mlx->m.mousebutton == 2 
		&& mlx->m.x < WINX)
	{
		mlx->al.x1 = (mlx->m.x / mlx->al.zoom + mlx->al.x1) - (mlx->m.x 
			/ (mlx->al.zoom / 1.3));
		mlx->al.y1 = (mlx->m.y / mlx->al.zoom + mlx->al.y1) - (mlx->m.y 
			/ (mlx->al.zoom / 1.3));
		mlx->al.zoom = mlx->al.zoom / 1.3;
		mlx->al.it_max--;
	}
}

void		mouse_hook(t_mlx *mlx)
{
	zoom_dezoom(mlx);
	if (mlx->m.tmpx > 1155 && mlx->m.tmpy > 469 && mlx->m.tmpx < 1188 
		&& mlx->m.tmpy < 490 && mlx->clr.chgcolor != 3)
		mlx->clr.chgcolor++;
	else if (mlx->m.tmpx > 1155 && mlx->m.tmpy > 469 && mlx->m.tmpx < 1188 
		&& mlx->m.tmpy < 490)
		mlx->clr.chgcolor = 0;
	if (mlx->m.tmpx > 1155 && mlx->m.tmpy < 515 && mlx->m.tmpx < 1188 
		&& mlx->m.tmpy > 494 && mlx->fract != 2 && mlx->m.tmpy!= 0)
	{
		mlx->fract++;
		init_var(mlx);
	}
	else if (mlx->m.tmpx > 1155 && mlx->m.tmpy < 515 && mlx->m.tmpx < 1188 
		&& mlx->m.tmpy > 494 && mlx->m.tmpy != 0)
	{
		mlx->fract = 0;
		init_var(mlx);
	}
	mlx->m.tmpx = 0;
	mlx->m.tmpy = 0;
}
