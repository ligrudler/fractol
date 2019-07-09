/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:56:08 by grudler           #+#    #+#             */
/*   Updated: 2019/07/09 17:59:33 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_mlx *mlx)
{
	*(int *)&mlx->canvas[mlx->y * mlx->size_line + mlx->x * 4] = mlx->color;
}

int		deal_key(void *param)
{
	t_mlx	*pmlx;
	double temp;

	pmlx = (t_mlx *)param;
	pmlx->x = 0;
	pmlx->y = 0;
	pmlx->x1 = -2.1;
	pmlx->y1 = -1.2;
	pmlx->it_max = 50;
	pmlx->zoom = 150;
	while (pmlx->x < WINX)
	{
		pmlx->y = 0;
		while (pmlx->y < WINY)
		{
			pmlx->c_r = pmlx->x / pmlx->zoom + pmlx->x1;
			pmlx->c_i = pmlx->y / pmlx->zoom + pmlx->y1;
			pmlx->z_r = 0;
			pmlx->z_i = 0;
			pmlx->it = 0;
			while (pmlx->z_r * pmlx->z_r + pmlx->z_i * pmlx->z_i < 4 && pmlx->it < pmlx->it_max)
			{
				temp = pmlx->z_r;
				pmlx->z_r = pmlx->z_r * pmlx->z_r - pmlx->z_i * pmlx->z_i + pmlx->c_r;
				pmlx->z_i = 2 * pmlx->z_i * temp + pmlx->c_i;
				pmlx->it++;
			}
			if (pmlx->it == pmlx->it_max)
			{
				pmlx->color = 0x00FFFF;
				put_pixel(pmlx);
			}
			pmlx->y++;
		}
		pmlx->x++;
	}
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, 50, 50);
	return (0);
	
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	
	if ((mlx.mlx_ptr = mlx_init()) == NULL)
		ft_error();
	if ((mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WINX, WINY, "fractol")) == NULL)
		ft_error();
	if ((mlx.img = mlx_new_image(mlx.mlx_ptr, WINX, WINY)) == NULL)
		ft_error();
	mlx.canvas = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);
	mlx_loop_hook(mlx.mlx_ptr, deal_key, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
