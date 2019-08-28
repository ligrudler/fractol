/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:25:18 by grudler           #+#    #+#             */
/*   Updated: 2019/08/28 16:55:59 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_palette(t_mlx *mlx)
{
	if (mlx->chgcolor == 0)
	{
		mlx->palette[0] = BLUE_0;
		mlx->palette[1] = BLUE_1;
		mlx->palette[2] = BLUE_2;
		mlx->palette[3] = BLUE_3;
		mlx->palette[4] = BLUE_4;
		mlx->palette[5] = BLUE_5;
		mlx->palette[6] = BLUE_6;
		mlx->palette[7] = BLUE_7;
		mlx->palette[8] = BLUE_8;
		mlx->palette[9] = BLUE_9;
		mlx->palette[10] = BLUE_10;
		mlx->palette[11] = BLUE_11;
		mlx->palette[12] = BLUE_12;
		mlx->palette[13] = BLUE_13;
		mlx->palette[14] = BLUE_14;
		mlx->palette[15] = BLUE_15;
	}
	if (mlx->chgcolor == 1)
	{
		mlx->palette[0] = BROWN_0;
		mlx->palette[1] = BROWN_1;
		mlx->palette[2] = BROWN_2;
		mlx->palette[3] = BROWN_3;
		mlx->palette[4] = BROWN_4;
		mlx->palette[5] = BROWN_5;
		mlx->palette[6] = BROWN_6;
		mlx->palette[7] = BROWN_7;
		mlx->palette[8] = BROWN_8;
		mlx->palette[9] = BROWN_9;
		mlx->palette[10] = BROWN_10;
		mlx->palette[11] = BROWN_11;
		mlx->palette[12] = BROWN_12;
		mlx->palette[13] = BROWN_13;
		mlx->palette[14] = BROWN_14;
		mlx->palette[15] = BROWN_15;
	}
	if (mlx->chgcolor == 2)
	{
		mlx->palette[0] = PURPLE_0;
		mlx->palette[1] = PURPLE_1;
		mlx->palette[2] = PURPLE_2;
		mlx->palette[3] = PURPLE_3;
		mlx->palette[4] = PURPLE_4;
		mlx->palette[5] = PURPLE_5;
		mlx->palette[6] = PURPLE_6;
		mlx->palette[7] = PURPLE_7;
		mlx->palette[8] = PURPLE_8;
		mlx->palette[9] = PURPLE_9;
		mlx->palette[10] = PURPLE_10;
		mlx->palette[11] = PURPLE_11;
		mlx->palette[12] = PURPLE_12;
		mlx->palette[13] = PURPLE_13;
		mlx->palette[14] = PURPLE_14;
		mlx->palette[15] = PURPLE_15;
	}
}