/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:35:25 by grudler           #+#    #+#             */
/*   Updated: 2019/09/05 14:40:42 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void		decalage_palette(t_mlx *mlx)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = mlx->clr.palette[0];
	while (i < 15)
	{
		mlx->clr.palette[i] = mlx->clr.palette[i + 1];
		i++;
	}
	mlx->clr.palette[i] = tmp;
	mlx->clr.j = 1;
}
