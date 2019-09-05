/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:25:18 by grudler           #+#    #+#             */
/*   Updated: 2019/09/05 14:49:50 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void		set_color1(t_mlx *mlx)
{
	mlx->clr.palette[0] = BLUE_0;
	mlx->clr.palette[1] = BLUE_1;
	mlx->clr.palette[2] = BLUE_2;
	mlx->clr.palette[3] = BLUE_3;
	mlx->clr.palette[4] = BLUE_4;
	mlx->clr.palette[5] = BLUE_5;
	mlx->clr.palette[6] = BLUE_6;
	mlx->clr.palette[7] = BLUE_7;
	mlx->clr.palette[8] = BLUE_8;
	mlx->clr.palette[9] = BLUE_9;
	mlx->clr.palette[10] = BLUE_10;
	mlx->clr.palette[11] = BLUE_11;
	mlx->clr.palette[12] = BLUE_12;
	mlx->clr.palette[13] = BLUE_13;
	mlx->clr.palette[14] = BLUE_14;
	mlx->clr.palette[15] = BLUE_15;
}

void		set_color2(t_mlx *mlx)
{
	mlx->clr.palette[0] = BROWN_0;
	mlx->clr.palette[1] = BROWN_1;
	mlx->clr.palette[2] = BROWN_2;
	mlx->clr.palette[3] = BROWN_3;
	mlx->clr.palette[4] = BROWN_4;
	mlx->clr.palette[5] = BROWN_5;
	mlx->clr.palette[6] = BROWN_6;
	mlx->clr.palette[7] = BROWN_7;
	mlx->clr.palette[8] = BROWN_8;
	mlx->clr.palette[9] = BROWN_9;
	mlx->clr.palette[10] = BROWN_10;
	mlx->clr.palette[11] = BROWN_11;
	mlx->clr.palette[12] = BROWN_12;
	mlx->clr.palette[13] = BROWN_13;
	mlx->clr.palette[14] = BROWN_14;
	mlx->clr.palette[15] = BROWN_15;
}

void		set_color3(t_mlx *mlx)
{
	mlx->clr.palette[0] = PURPL_0;
	mlx->clr.palette[1] = PURPL_1;
	mlx->clr.palette[2] = PURPL_2;
	mlx->clr.palette[3] = PURPL_3;
	mlx->clr.palette[4] = PURPL_4;
	mlx->clr.palette[5] = PURPL_5;
	mlx->clr.palette[6] = PURPL_6;
	mlx->clr.palette[7] = PURPL_7;
	mlx->clr.palette[8] = PURPL_8;
	mlx->clr.palette[9] = PURPL_9;
	mlx->clr.palette[10] = PURPL_10;
	mlx->clr.palette[11] = PURPL_11;
	mlx->clr.palette[12] = PURPL_12;
	mlx->clr.palette[13] = PURPL_13;
	mlx->clr.palette[14] = PURPL_14;
	mlx->clr.palette[15] = PURPL_15;
}

void		set_color4(t_mlx *mlx)
{
	mlx->clr.palette[0] = RED_0;
	mlx->clr.palette[1] = RED_1;
	mlx->clr.palette[2] = RED_2;
	mlx->clr.palette[3] = RED_3;
	mlx->clr.palette[4] = RED_4;
	mlx->clr.palette[5] = RED_5;
	mlx->clr.palette[6] = RED_6;
	mlx->clr.palette[7] = RED_7;
	mlx->clr.palette[8] = RED_8;
	mlx->clr.palette[9] = RED_9;
	mlx->clr.palette[10] = RED_10;
	mlx->clr.palette[11] = RED_11;
	mlx->clr.palette[12] = RED_12;
	mlx->clr.palette[13] = RED_13;
	mlx->clr.palette[14] = RED_14;
	mlx->clr.palette[15] = RED_15;
}

void		fill_palette(t_mlx *mlx)
{
	if (mlx->clr.chgcolor == 0 && mlx->clr.j == 0)
		set_color1(mlx);
	if (mlx->clr.chgcolor == 1 && mlx->clr.j == 0)
		set_color2(mlx);
	if (mlx->clr.chgcolor == 2 && mlx->clr.j == 0)
		set_color3(mlx);
	if (mlx->clr.chgcolor == 3 && mlx->clr.j == 0)
		set_color4(mlx);
}
