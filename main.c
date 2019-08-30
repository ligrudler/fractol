/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:56:08 by grudler           #+#    #+#             */
/*   Updated: 2019/08/30 22:35:46 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_mlx *mlx, int color)
{
	if (mlx->al.x <= WINX && mlx->al.y <= WINY)
		*(int *)&mlx->i.canvas[mlx->al.y * mlx->i.size_line + mlx->al.x * 4] 
			= color;
}

void	init_mlx(t_mlx *mlx)
{
	if ((mlx->mlx_ptr = mlx_init()) == NULL)
		ft_error();
	if ((mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINALL, WINY, "fractol")) 
		== NULL)
		ft_error();
	if ((mlx->i.img = mlx_new_image(mlx->mlx_ptr, WINX + 1, WINY)) == NULL)
		ft_error();
	mlx->i.canvas = mlx_get_data_addr(mlx->i.img, &mlx->i.bpp, &mlx->i.size_line,
		 &mlx->i.endian);
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
		init_mlx(&mlx);
		print_legend(&mlx);
		init_var(&mlx);
		mlx_loop_hook(mlx.mlx_ptr, multi_thread, &mlx);
		mlx_hook(mlx.win_ptr, MOTION_NOTIFY, 0, motion_notify, &mlx);
		mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
		mlx_hook(mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
		mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\" wesh");
	return (0);
}
