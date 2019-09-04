/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:12:43 by grudler           #+#    #+#             */
/*   Updated: 2019/09/04 10:12:37 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/fractol.h"

int		key_press(int key, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	pmlx->keyboard[key] = 1;
	return (0);
}

int		key_release(int key, void *param)
{
	t_mlx *pmlx;

	pmlx = (t_mlx *)param;
	pmlx->keyboard[key] = 0;
	return (0);
}

void	init_key(t_mlx *mlx)
{
	if (mlx->keyboard[KEY_ESCAPE])
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->i.img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	if ((mlx->keyboard[KEY_LEFT] && !mlx->keyboard[KEY_RIGHT])
		|| (mlx->keyboard[KEY_RIGHT] && !mlx->keyboard[KEY_LEFT]))
		mlx->a.x1 += mlx->keyboard[KEY_LEFT] ? 10 / mlx->a.zoom: -10
			/ mlx->a.zoom;
	if ((mlx->keyboard[KEY_DOWN] && !mlx->keyboard[KEY_UP])
		|| (mlx->keyboard[KEY_UP] && !mlx->keyboard[KEY_DOWN]))
		mlx->a.y1 += mlx->keyboard[KEY_UP] ? 10 / mlx->a.zoom: -10
			/ mlx->a.zoom;
	if (mlx->keyboard[KEY_SPACEBAR])
		init_var(mlx);
	if (mlx->keyboard[KEY_I])
		mlx->a.it_max += 10;
	if (mlx->keyboard[KEY_O] && mlx->a.it_max > 10)
		mlx->a.it_max -= 10;
	if (mlx->keyboard[KEY_D] && mlx->clr.end <= 200)
		mlx->clr.end += 1;
	if (mlx->keyboard[KEY_F] && mlx->clr.end >= 1)
		mlx->clr.end -= 1;
	if (mlx->keyboard[KEY_N])
	{
		int i;
		int tmp;

		i = 0;
		tmp = mlx->clr.palette[0];
		while ( i < 15)
		{
			mlx->clr.palette[i] = mlx->clr.palette[i + 1];
			i++;
		}
		mlx->clr.palette[i] = tmp;
		mlx->clr.j = 1;
	}
}