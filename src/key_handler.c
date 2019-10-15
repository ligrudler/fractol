/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:12:43 by grudler           #+#    #+#             */
/*   Updated: 2019/10/15 15:10:15 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int			key_press(int key, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	pmlx->keyboard[key] = 1;
	return (0);
}

int			key_release(int key, void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	pmlx->keyboard[key] = 0;
	return (0);
}

void		key_move(t_mlx *mlx)
{
	if ((mlx->keyboard[KEY_LEFT] && !mlx->keyboard[KEY_RIGHT])
		|| (mlx->keyboard[KEY_RIGHT] && !mlx->keyboard[KEY_LEFT]))
		mlx->a.x1 += mlx->keyboard[KEY_LEFT] ? 10 / mlx->a.zoom : -10
			/ mlx->a.zoom;
	if ((mlx->keyboard[KEY_DOWN] && !mlx->keyboard[KEY_UP])
		|| (mlx->keyboard[KEY_UP] && !mlx->keyboard[KEY_DOWN]))
		mlx->a.y1 += mlx->keyboard[KEY_UP] ? 10 / mlx->a.zoom : -10
			/ mlx->a.zoom;
}

void		init_key(t_mlx *mlx)
{
	if (mlx->keyboard[KEY_ESCAPE])
		clean_mlx(mlx, 1);
	key_move(mlx);
	if (mlx->keyboard[KEY_SPACEBAR])
		init_var(mlx);
	if (mlx->keyboard[KEY_I] && mlx->a.it_max < 2000)
		mlx->a.it_max += 10;
	if (mlx->keyboard[KEY_O] && mlx->a.it_max > 10)
		mlx->a.it_max -= 10;
	if (mlx->keyboard[KEY_D] && mlx->clr.end <= 200)
		mlx->clr.end += 1;
	if (mlx->keyboard[KEY_F] && mlx->clr.end >= 1)
		mlx->clr.end -= 1;
	if (mlx->keyboard[KEY_N])
		decalage_palette(mlx);
}
