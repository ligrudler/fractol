/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:55:38 by grudler           #+#    #+#             */
/*   Updated: 2019/09/04 11:57:14 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	init_all(t_mlx *pmlx)
{
	if (pmlx->fract == 0)
	{
		pmlx->a.x1 = -2.1;
		pmlx->a.y1 = -1.5;
	}
	else if (pmlx->fract == 1)
	{
		pmlx->a.x1 = -1.6;
		pmlx->a.y1 = -1.6;
	}
	else if (pmlx->fract == 2)
	{
		pmlx->a.x1 = -2.0;
		pmlx->a.y1 = -2.0;
	}
	else if (pmlx->fract == 3)
	{
		pmlx->a.x1 = -1.6;
		pmlx->a.y1 = -1.5;
	}
}

void	init_var(t_mlx *pmlx)
{
	pmlx->a.x = 0;
	pmlx->a.y = 0;
	pmlx->clr.chgcolor = 0;
	pmlx->a.it_max = 100;
	pmlx->a.zoom = ZOOM;
	pmlx->stop = 1;
	pmlx->m.j_x = 400;
	pmlx->m.j_y = 400;
	pmlx->clr.gradient = 0;
	pmlx->clr.end = 15;
	pmlx->clr.color = 0x0000FF;
	pmlx->clr.j = 0;
	pmlx->clr.dec = 0;
	init_all(pmlx);
}