/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:56:08 by grudler           #+#    #+#             */
/*   Updated: 2019/08/29 23:04:38 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_mlx *mlx, int color)
{
	if (mlx->x <= WINX && mlx->y <= WINY)
		*(int *)&mlx->i.canvas[mlx->y * mlx->i.size_line + mlx->x * 4] = color;
}

int	ft_which_frac(char **argv, t_mlx *mlx)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mlx->fract = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		mlx->fract = 1;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		mlx->fract = 2;
	else
	{
		ft_putendl("Usage /fractol \"mandelbrot\"");
		return (0);
	}
	return (1);

}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	
	if (argc == 2)
	{
		if (ft_which_frac(argv, &mlx) == 0)
			return (0);
		if ((mlx.mlx_ptr = mlx_init()) == NULL)
			ft_error();
		if ((mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WINALL, WINY, "fractol")) == NULL)
			ft_error();
		if ((mlx.i.img = mlx_new_image(mlx.mlx_ptr, WINX, WINY)) == NULL)
			ft_error();
		mlx.i.canvas = mlx_get_data_addr(mlx.i.img, &mlx.i.bpp, &mlx.i.size_line, &mlx.i.endian);
		print_legend(&mlx);
		init_var(&mlx);
		mlx_loop_hook(mlx.mlx_ptr, multi_thread, &mlx);
		mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
		mlx_hook(mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
		mlx_hook(mlx.win_ptr, EV_MOUSE_PRESS, 0, mouse_press, &mlx);
		mlx_hook(mlx.win_ptr, EV_MOUSE_RELEA, 0, mouse_release, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\" wesh");
	return (0);
}
