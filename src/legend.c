/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:29:53 by grudler           #+#    #+#             */
/*   Updated: 2019/09/07 19:14:42 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void		print_var(t_mlx *mlx)
{
	t_leg	leg;
	char	*str;

	sprintf(leg.zoom, "Zoom :             x%.2f", mlx->a.zoom / ZOOM);
	mlx_string_put(mlx->ptr, mlx->win_ptr, 840, 195, 0xFFFFFF, leg.zoom);
	mlx_string_put(mlx->ptr, mlx->win_ptr, 840, 220, 0xFFFFFF,
		"Iterations max : ");
	str = ft_itoa(mlx->a.it_max);
	mlx_string_put(mlx->ptr, mlx->win_ptr, 1030, 220, 0xFFFFFF, str);
	free(str);
	mlx_string_put(mlx->ptr, mlx->win_ptr, 1120, 220, 0xFFFFFF, "(I / O)");
	if (mlx->stop == 1 && (mlx->fract == 1 || mlx->fract == 3))
		mlx_string_put(mlx->ptr, mlx->win_ptr, 70, 70, 0xFFFFFF, "STOP");
}

void		menu_gradient(t_leg leg, t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win_ptr, 915, 605, 0x191970, "DEGRADE");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 860, 640, 0xFFFFFF,
		"BLEU  ROSE  NOIR  ROUGE ");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 900, 665, 0xFFFFFF, "OU MULTI :");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 860, 690, 0xFFFFFF,
		"ROSE  VERT  JAUNE");
	if (mlx->clr.color == 0xCC33FF)
		mlx_string_put(mlx->ptr, mlx->win_ptr, 860, 690, 0xCC33FF, "ROSE");
	else if (mlx->clr.color == 0x0000FF)
		mlx_string_put(mlx->ptr, mlx->win_ptr, 860, 640, 0x0000FF, "BLEU");
	else if (mlx->clr.color == 0xFF00FF)
		mlx_string_put(mlx->ptr, mlx->win_ptr, 920, 640, 0xFF00FF, "ROSE");
	else if (mlx->clr.color == 0x000000)
		mlx_string_put(mlx->ptr, mlx->win_ptr, 980, 640, 0x000000, "NOIR");
	else if (mlx->clr.color == 0xFF0000)
		mlx_string_put(mlx->ptr, mlx->win_ptr, 1040, 640, 0xFF0000, "ROUGE");
	else if (mlx->clr.color == 0x33CC33)
		mlx_string_put(mlx->ptr, mlx->win_ptr, 920, 690, 0x33CC33, "VERT");
	else if (mlx->clr.color == 0xFFCC33)
		mlx_string_put(mlx->ptr, mlx->win_ptr, 980, 690, 0xFFCC33, "JAUNE");
	sprintf(leg.deg, "Degrade :          x%.2f", mlx->clr.end / 15);
	mlx_string_put(mlx->ptr, mlx->win_ptr, 840, 245, 0xFFFFFF, leg.deg);
	mlx_string_put(mlx->ptr, mlx->win_ptr, 840, 730, 0x191970,
		"Ajuster degrade : D / F");
}

void		print_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win_ptr, 915, 605, 0xFFFFFF,
		"DEGRADE   OU   ZONE ?");
	if (mlx->clr.gradient == 0)
		mlx_string_put(mlx->ptr, mlx->win_ptr, 1065, 605, 0x191970, "ZONE");
	if (mlx->clr.gradient == 1)
		menu_gradient(mlx->l, mlx);
	else if (mlx->clr.gradient == 0)
	{
		mlx_string_put(mlx->ptr, mlx->win_ptr, 860, 660, 0xFFFFFF,
			"BLEU  SABLE  VIOLET  ROUGE");
		if (mlx->clr.chgcolor == 0)
			mlx_string_put(mlx->ptr, mlx->win_ptr, 860, 660, 0x08004C, "BLEU");
		else if (mlx->clr.chgcolor == 1)
			mlx_string_put(mlx->ptr, mlx->win_ptr, 920, 660, 0xFFE9C7, "SABLE");
		else if (mlx->clr.chgcolor == 2)
			mlx_string_put(mlx->ptr, mlx->win_ptr, 990, 660, 0x5F1850,
				"VIOLET");
		else if (mlx->clr.chgcolor == 3)
			mlx_string_put(mlx->ptr, mlx->win_ptr, 1070, 660, 0x8F000D,
				"ROUGE");
		mlx_string_put(mlx->ptr, mlx->win_ptr, 840, 700, 0x191970,
			"Decaler couleurs : N");
		mlx_string_put(mlx->ptr, mlx->win_ptr, 840, 730, 0x191970,
			"En continu : clic gauche");
	}
}

int			print_legend(t_mlx *mlx)
{
	color_box_legend(mlx);
	print_name(mlx);
	print_var(mlx);
	print_menu(mlx);
	mlx_string_put(mlx->ptr, mlx->win_ptr, 950, 115, 0xFFFFFF,
		"INFORMATIONS");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 960, 305, 0xFFFFFF,
		"COMMANDES");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 915, 545, 0xFFFFFF,
		"GESTION DES COULEURS");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 810, 360, 0xFFFFFF,
		"Changer de fractale ? c'est ici =>");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 810, 385, 0xFFFFFF,
		"Pour zoomer : molette");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 810, 410, 0xFFFFFF,
		"Pour bouger : fleches directionnelles");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 810, 435, 0xFFFFFF,
		"Reset :       barre d'espace");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 810, 460, 0xFFFFFF,
		"Mouvement julia :  clic droit");
	mlx_string_put(mlx->ptr, mlx->win_ptr, 810, 485, 0xFFFFFF,
		"Quitter :     echap");
	return (0);
}
