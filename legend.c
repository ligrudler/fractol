/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:17:49 by grudler           #+#    #+#             */
/*   Updated: 2019/08/28 12:38:10 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_box_legend(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y <= WINALL)
	{
		x = WINX;
		while (x <= WINALL)
		{
			if ((y >= 150 && y <= 400) || y <= 100 || y >= 450)
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x468DB4);
			else if ((y > 100 && y < 150) || (y > 400 && y < 450))
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x191970);
			x++;
		}
		y++;
	}
	y = 468;
	while (y > 467 && y < 492)
	{
		x = 1156;
		while (x > 1155 && x < 1190)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x800000);
			x++;
		}
		y++;
	}
}

void	print_legend(t_mlx *mlx)
{
	color_box_legend(mlx);
	if (mlx->fract == 0)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 0x191970, "MANDELBROT");
	if (mlx->fract == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 0x0000CD, "JULIA");
	if (mlx->fract == 2)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 0x0000CD, "BURNINGSHIP");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 950, 115, 0xFFFFFF, "INFORMATIONS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 960, 415, 0xFFFFFF, "COMMANDS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 470, 0xFFFFFF, "Changer de couleur ? c'est ici =>");
}