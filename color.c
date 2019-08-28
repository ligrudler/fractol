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
		mlx->palette[0] = JULIABROT_0;
		mlx->palette[1] = JULIABROT_1;
		mlx->palette[2] = JULIABROT_2;
		mlx->palette[3] = JULIABROT_3;
		mlx->palette[4] = JULIABROT_4;
		mlx->palette[5] = JULIABROT_5;
		mlx->palette[6] = JULIABROT_6;
		mlx->palette[7] = JULIABROT_7;
		mlx->palette[8] = JULIABROT_8;
		mlx->palette[9] = JULIABROT_9;
		mlx->palette[10] = JULIABROT_10;
		mlx->palette[11] = JULIABROT_11;
		mlx->palette[12] = JULIABROT_12;
		mlx->palette[13] = JULIABROT_13;
		mlx->palette[14] = JULIABROT_14;
		mlx->palette[15] = JULIABROT_15;
	}
	if (mlx->chgcolor == 1)
	{
		mlx->palette[0] = 0xFFF8DC;
		mlx->palette[1] = 0xFFEBCD;
		mlx->palette[2] = 0xFFDEAD;
		mlx->palette[3] = 0xF5DEB3;
		mlx->palette[4] = 0xDEB887;
		mlx->palette[5] = 0xFFE4C4;
		mlx->palette[6] = 0xD2B48C;
		mlx->palette[7] = 0xBC8F8F;
		mlx->palette[8] = 0xF4A460;
		mlx->palette[9] = 0xDAA520;
		mlx->palette[10] = 0xB8860B;
		mlx->palette[11] = 0xCD853F;
		mlx->palette[12] = 0xD2691E;
		mlx->palette[13] = 0x8B4513;
		mlx->palette[14] = 0xA0522D;
		mlx->palette[15] = 0xA52A2A;
	}
}