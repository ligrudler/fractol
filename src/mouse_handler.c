/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:14 by grudler           #+#    #+#             */
/*   Updated: 2019/10/15 15:37:44 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int			motion_notify(int x, int y, void *param)
{
	t_mlx *pmlx;

	pmlx = (t_mlx *)param;
	if (x < 0 || x >= WINX || y >= WINY || y < 0 || pmlx->stop == 1)
		return (0);
	pmlx->m.j_x = x;
	pmlx->m.j_y = y;
	return (0);
}

void		zoom_dezoom(int button, int x, int y, t_mlx *mlx)
{
	if (button == UP_MOLETTE && x < WINX)
	{
		mlx->a.x1 = (x / mlx->a.zoom + mlx->a.x1) - (x / (mlx->a.zoom * 1.1));
		mlx->a.y1 = (y / mlx->a.zoom + mlx->a.y1) - (y / (mlx->a.zoom * 1.1));
		mlx->a.zoom = mlx->a.zoom * 1.1;
	}
	if (button == DOWN_MOLETTE && x < WINX && mlx->a.zoom > 0)
	{
		mlx->a.x1 = (x / mlx->a.zoom + mlx->a.x1) - (x / (mlx->a.zoom / 1.1));
		mlx->a.y1 = (y / mlx->a.zoom + mlx->a.y1) - (y / (mlx->a.zoom / 1.1));
		mlx->a.zoom = mlx->a.zoom / 1.1;
	}
}

void		change_color(int x, int y, t_mlx *mlx)
{
	if (x > 860 && x < 900 && y > 665 && y < 678)
	{
		mlx->clr.chgcolor = 0;
		mlx->clr.j = 0;
	}
	else if (x > 920 && x < 970 && y > 665 && y < 678)
	{
		mlx->clr.chgcolor = 1;
		mlx->clr.j = 0;
	}
	else if (x > 990 && x < 1050 && y > 665 && y < 678)
	{
		mlx->clr.chgcolor = 2;
		mlx->clr.j = 0;
	}
	else if (x > 1070 && x < 1120 && y > 665 && y < 678)
	{
		mlx->clr.chgcolor = 3;
		mlx->clr.j = 0;
	}
}

void		set_menu(int x, int y, t_mlx *mlx)
{
	if (x > 915 && x < 985 && y > 610 && y < 626)
		mlx->clr.gradient = 1;
	else if (x > 1065 && y > 610 && y < 626 && x < 1105)
		mlx->clr.gradient = 0;
	else if (x > 860 && x < 900 && y > 645 && y < 661)
		mlx->clr.color = 0x0000FF;
	else if (x > 860 && x < 900 && y > 695 && y < 711)
		mlx->clr.color = 0xCC33FF;
	else if (x > 920 && x < 960 && y > 645 && y < 661)
		mlx->clr.color = 0xFF00FF;
	else if (x > 980 && x < 1020 && y > 645 && y < 661)
		mlx->clr.color = 0x000000;
	else if (x > 1040 && x < 1090 && y > 645 && y < 661)
		mlx->clr.color = 0xFF0000;
	else if (x > 920 && x < 960 && y > 695 && y < 711)
		mlx->clr.color = 0x33CC33;
	else if (x > 980 && x < 1030 && y > 695 && y < 711)
		mlx->clr.color = 0xFFCC33;
	change_color(x, y, mlx);
}

int			mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	zoom_dezoom(button, x, y, mlx);
	if (button == CLIC_DROIT)
		mlx->stop = (mlx->stop == 1 ? 0 : 1);
	if (button == CLIC_GAUCHE && x < WINX && y < WINY && y > 0)
		mlx->clr.dec = (mlx->clr.dec == 1 ? 0 : 1);
	if (x > 1155 && y < 380 && x < 1188 && y > 359 && mlx->fract != 3)
	{
		mlx->fract++;
		init_var(mlx);
	}
	else if (x > 1155 && y < 380 && x < 1188 && y > 359)
	{
		mlx->fract = 0;
		init_var(mlx);
	}
	set_menu(x, y, mlx);
	return (0);
}
