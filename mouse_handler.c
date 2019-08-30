/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:14 by grudler           #+#    #+#             */
/*   Updated: 2019/08/30 11:27:25 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_dezoom(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5 && x < WINX)
	{
		mlx->al.x1 = (x / mlx->al.zoom + mlx->al.x1) - (x / (mlx->al.zoom * 1.3	));
		mlx->al.y1 = (y / mlx->al.zoom + mlx->al.y1) - (y / (mlx->al.zoom * 1.3));
		mlx->al.zoom = mlx->al.zoom * 1.3;
	}
	if (button == 4 && x < WINX)
	{
		mlx->al.x1 = (x / mlx->al.zoom + mlx->al.x1) - (x / (mlx->al.zoom / 1.3	));
		mlx->al.y1 = (y / mlx->al.zoom + mlx->al.y1) - (y / (mlx->al.zoom / 1.3));
		mlx->al.zoom = mlx->al.zoom / 1.3;
	}
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	zoom_dezoom(button, x, y, mlx);
	if (x > 1155 && y > 469 && x < 1188 
		&& y < 490 && mlx->clr.chgcolor != 3)
		mlx->clr.chgcolor++;
	else if (x > 1155 && y > 469 && x < 1188 
		&& y < 490)
		mlx->clr.chgcolor = 0;
	if (x > 1155 && y < 515 && x < 1188 
		&& y > 494 && mlx->fract != 2)
	{
		mlx->fract++;
		init_var(mlx);
	}
	else if (x > 1155 && y < 515 && x < 1188 
		&& y > 494)
	{
		mlx->fract = 0;
		init_var(mlx);
	}
	return (0);
}