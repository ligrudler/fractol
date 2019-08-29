/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:14 by grudler           #+#    #+#             */
/*   Updated: 2019/08/29 17:21:35 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*pmlx;
	
	pmlx = (t_mlx *)param;
	pmlx->mousebutton = button;
	pmlx->mousex = x;
	pmlx->mousey = y;
	pmlx->mouseboard[button] = 1;
	pmlx->tmpx = pmlx->mousex;
	pmlx->tmpy = pmlx->mousey;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	pmlx->mousex = x;
	pmlx->mousey = y;
	pmlx->mouseboard[button] = 0;
	pmlx->tmpx = pmlx->mousex;
	pmlx->tmpy = pmlx->mousey;
	return (0);
}

void		mouse_hook(t_mlx *mlx)
{
	if (mlx->mouseboard[mlx->mousebutton] && mlx->mousebutton == 1 && mlx->mousex < WINX)
	{
		mlx->x1 = (mlx->mousex / mlx->zoom + mlx->x1) - (mlx->mousex / (mlx->zoom * 1.3	));
		mlx->y1 = (mlx->mousey / mlx->zoom + mlx->y1) - (mlx->mousey / (mlx->zoom * 1.3));
		mlx->zoom = mlx->zoom * 1.3;
		mlx->it_max++;
	}
	if (mlx->mouseboard[mlx->mousebutton] && mlx->mousebutton == 2 && mlx->mousex < WINX)
	{
		mlx->x1 = (mlx->mousex / mlx->zoom + mlx->x1) - (mlx->mousex / (mlx->zoom / 1.3));
		mlx->y1 = (mlx->mousey / mlx->zoom + mlx->y1) - (mlx->mousey / (mlx->zoom / 1.3));
		mlx->zoom = mlx->zoom / 1.3;
		mlx->it_max--;
	}
	if (mlx->tmpx > 1155 && mlx->tmpy > 467 && mlx->tmpx < 1190 && mlx->tmpy < 492 && mlx->chgcolor != 2)
		mlx->chgcolor++;
	else if (mlx->tmpx > 1155 && mlx->tmpy > 467 && mlx->tmpx < 1190 && mlx->tmpy < 492)
		mlx->chgcolor = 0;
	if (mlx->tmpx> 800 && mlx->tmpy < 150 && mlx->fract != 2 && mlx->tmpy!= 0)
	{
		mlx->fract++;
		init_var(mlx);
	}
	else if (mlx->tmpx > 800 && mlx->tmpy < 150 && mlx->tmpy != 0)
	{
		mlx->fract = 0;
		init_var(mlx);
	}
	mlx->tmpx = 0;
	mlx->tmpy = 0;
}
