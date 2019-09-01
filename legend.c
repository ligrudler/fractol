/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:29:53 by grudler           #+#    #+#             */
/*   Updated: 2019/09/02 00:49:26 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_little_square(t_mlx *mlx)
{
	int x;
	int y;
	
	y = 360;
	while (y++ > 359 && y < 380)
	{
		x = 1156;
		while (x++ > 1155 && x < 1188)
			put_pixel_to_img(mlx, 0x191970, x, y);
	}
}

void	color_box_legend(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y++ <= WINY)
	{
		x = WINX + 1;
		while (x++ <= WINALL)
		{
			if (y <= 100 || y >= 580 || (y >= 150 && y <= 290) || (y >= 340 && y <= 530))
				put_pixel_to_img(mlx, 0x468DB4, x, y);
			else if (((y > 100 && y < 150) || (y > 290 && y < 340) || (y > 530 && y < 580)) && x > 800)
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
	
	sprintf(leg.zoom, "Zoom :             x%.2f", mlx->al.zoom / ZOOM);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 195, 0xFFFFFF, leg.zoom);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 220, 0xFFFFFF, "Iterations max : ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1030, 220, 0xFFFFFF, ft_itoa(mlx->al.it_max));
	if (mlx->stop == 1 && mlx->fract == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 70, 70, 0xFFFFFF, "STOP");
}

void	test_menu(t_mlx *mlx)
{
		t_leg	leg;
		
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 915, 605, 0xFFFFFF, "DEGRADE   OU   ZONE ?");
		if (mlx->clr.gradient == 0)
			mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1065, 605, 0x191970, "ZONE");
		if (mlx->clr.gradient == 1)
		{
			mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 915, 605, 0x191970, "DEGRADE");
			mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 860, 640, 0xFFFFFF, "BLEU  ROSE  NOIR  ROUGE ");
			mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 900, 665, 0xFFFFFF, "OU MULTI :");
			mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 860, 690, 0xFFFFFF, "ROSE  VERT  JAUNE");
			if (mlx->clr.color == 0xCC33FF)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 860, 690, 0xCC33FF, "ROSE");
			else if (mlx->clr.color == 0x0000FF)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 860, 640, 0x0000FF, "BLEU");
			else if (mlx->clr.color == 0xFF00FF)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 920, 640, 0xFF00FF, "ROSE");	
			else if (mlx->clr.color == 0x000000)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 980, 640, 0x000000, "NOIR");
			else if (mlx->clr.color == 0xFF0000)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1040, 640, 0xFF0000, "ROUGE");
			else if (mlx->clr.color == 0x33CC33)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 920, 690, 0x33CC33, "VERT");
			else if (mlx->clr.color == 0xFFCC33)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 980, 690, 0xFFCC33, "JAUNE");
			sprintf(leg.deg, "Degrade :          x%.2f", mlx->clr.end / 15);
			mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 245, 0xFFFFFF, leg.deg);
			mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 840, 730, 0x191970, "Ajuster degrade : D / F");
		}
		else if (mlx->clr.gradient == 0)
		{
			mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 860, 660, 0xFFFFFF, "BLEU  SABLE  VIOLET  ROUGE");
			if (mlx->clr.chgcolor == 0)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 860, 660, 0x08004C, "BLEU");
			else if (mlx->clr.chgcolor == 1)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 920, 660, 0xFFE9C7, "SABLE");
			else if (mlx->clr.chgcolor == 2)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 990, 660, 0x5F1850, "VIOLET");
			else if (mlx->clr.chgcolor == 3)
				mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1070, 660, 0x8F000D, "ROUGE");
		}


}

int		print_legend(t_mlx *mlx)
{
	color_box_legend(mlx);
	print_name(mlx);
	print_var(mlx);
	test_menu(mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 950, 115, 0xFFFFFF, 
		"INFORMATIONS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 960, 305, 0xFFFFFF, 
		"COMMANDES");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 915, 545, 0xFFFFFF, 
		"GESTION DES COULEURS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 360, 0xFFFFFF, 
		"Changer de fractale ? c'est ici =>");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 385, 0xFFFFFF, 
		"Pour zoomer : molette");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 410, 0xFFFFFF, 
		"Pour bouger : fleches directionnelles");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 435, 0xFFFFFF, 
		"Reset :       barre d'espace");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 460, 0xFFFFFF, 
		"Mouvement julia :  clic droit");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 485, 0xFFFFFF, 
		"Quitter :     echap");
	return (0);
}