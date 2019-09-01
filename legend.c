/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:29:53 by grudler           #+#    #+#             */
/*   Updated: 2019/08/31 23:30:42 by grudler          ###   ########.fr       */
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
			put_pixel_to_img(mlx, 0xFFFFFF, x, y);
	}
	y = 495;
	while (y++ > 494 && y < 515)
	{
		x = 1156;
		while (x++ > 1155 && x < 1188)
			put_pixel_to_img(mlx, 0x800000, x, y);
	}
}

void	color_box_legend(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y++ < WINY)
	{
		x = WINX + 1;
		while (x++ < WINALL)
		{
			if ((y >= 150 && y <= 400) || y <= 100 || y >= 450)
				//mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x468DB4);
				put_pixel_to_img(mlx, 0x468DB4, x, y);
			else if ((y > 100 && y < 150) || (y > 400 && y < 450))
				//mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x191970);
				put_pixel_to_img(mlx, 0x191970, x, y);
		}
	}
	draw_little_square(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->i.img, 0, 0);
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

void	print_var(t_mlx *mlx)
{
	t_leg	leg;
	
	sprintf(leg.zoom, "Zoom =             x%.2f", mlx->al.zoom / ZOOM);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 300, 0xFFFFFF, leg.zoom);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 260, 0xFFFFFF, "Iterations max : ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1030, 260, 0xFFFFFF, ft_itoa(mlx->al.it_max));
	if (mlx->stop == 1 && mlx->fract == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 70, 70, 0xFFFFFF, "STOP");
	if (mlx->clr.chgcolor == 0)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 230, 0xFFFFFF, "Couleur : BLEU");
	else if (mlx->clr.chgcolor == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 230, 0xFFFFFF, "Couleur : SABLE");
	else if (mlx->clr.chgcolor == 2)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 230, 0xFFFFFF, "Couleur : VIOLET");
	else if (mlx->clr.chgcolor == 3)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 230, 0xFFFFFF, "Couleur : RED");
}

int		print_legend(t_mlx *mlx)
{
	color_box_legend(mlx);
	print_name(mlx);
	print_var(mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 950, 115, 0xFFFFFF, 
		"INFORMATIONS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 960, 415, 0xFFFFFF, 
		"COMMANDS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 470, 0xFFFFFF, 
		"Changer de couleur ?  c'est ici =>");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 495, 0xFFFFFF, 
		"Changer de fractale ? c'est ici =>");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 520, 0xFFFFFF, 
		"Pour zoomer : molette");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 545, 0xFFFFFF, 
		"Pour bouger : fleches directionnelles");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 570, 0xFFFFFF, 
		"Reset :       barre d'espace");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 595, 0xFFFFFF, 
		"Stop julia :  clic droit");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 620, 0xFFFFFF, 
		"Quitter :     echap");
	return (0);
}