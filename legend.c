/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:29:53 by grudler           #+#    #+#             */
/*   Updated: 2019/08/29 23:37:48 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_little_square(t_mlx *mlx)
{
	int x;
	int y;
	
	y = 470;
	while (y++ > 469 && y < 490)
	{
		x = 1156;
		while (x++ > 1155 && x < 1188)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x800000);
	}
	y = 495;
	while (y++ > 494 && y < 515)
	{
		x = 1156;
		while (x++ > 1155 && x < 1188)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x800000);
	}
}

void	color_box_legend(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y++ <= WINY)
	{
		x = WINX;
		while (x++ <= WINALL)
		{
			if ((y >= 150 && y <= 400) || y <= 100 || y >= 450)
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x468DB4);
			else if ((y > 100 && y < 150) || (y > 400 && y < 450))
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x191970);
		}
	}
	draw_little_square(mlx);
}

void	print_name(t_mlx *mlx)
{
	if (mlx->fract == 0)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 
			0x191970, "MANDELBROT");
	if (mlx->fract == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 
			0x0000CD, "JULIA");
	if (mlx->fract == 2)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 0x0000CD, 
			"BURNINGSHIP");
}
void	print_legend(t_mlx *mlx)
{
	color_box_legend(mlx);
	print_name(mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 950, 115, 0xFFFFFF, 
		"INFORMATIONS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 960, 415, 0xFFFFFF, 
		"COMMANDS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 470, 0xFFFFFF, 
		"Changer de couleur ? c'est ici =>");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 495, 0xFFFFFF, 
		"Changer de fractale ? c'est ici =>");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 520, 0xFFFFFF, 
		"Pour zoomer : click droit");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 545, 0xFFFFFF, 
		"Pour bouger : flèches directionnelles");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 570, 0xFFFFFF, 
		"Reset : barre d'espace");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 595, 0xFFFFFF, 
		"Quitter : echap");
}