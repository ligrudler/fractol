/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:25:18 by grudler           #+#    #+#             */
/*   Updated: 2019/08/28 16:56:00 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_palette(t_mlx *mlx)
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
	mlx->palette[15] = 0xa52A2A;
}