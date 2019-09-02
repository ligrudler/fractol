/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leg_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:12:04 by grudler           #+#    #+#             */
/*   Updated: 2019/09/02 13:16:48 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	draw_little_square(t_mlx *mlx)
{
	int x;
	int y;
	
	y = 360;
	while (y++ > 359 && y < 380)
	{
		x = 1156;
		while (x++ > 1155 && x < 1188)
			put_pixel_to_img(mlx, 0x191970, x, y);
	}
}

void	color_box_legend(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y++ <= WINY)
	{
		x = WINX + 1;
		while (x++ <= WINALL)
		{
			if (y <= 100 || y >= 580 || (y >= 150 && y <= 290) || (y >= 340
				&& y <= 530))
				put_pixel_to_img(mlx, 0x468DB4, x, y);
			else if (((y > 100 && y < 150) || (y > 290 && y < 340) || (y > 530
				&& y < 580)) && x > 800)
				put_pixel_to_img(mlx, 0x191970, x, y);
		}
	}
	draw_little_square(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->i.img, 0, 0);
}

void	print_name(t_mlx *mlx)
{
	if (mlx->fract == 0)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 
			0x191970, "MANDELBROT");
	if (mlx->fract == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 
			0x0000CD, "JULIA");
	if (mlx->fract == 2)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 0x0000CD, 
			"BURNINGSHIP");
}