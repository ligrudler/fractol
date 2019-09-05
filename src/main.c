/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:56:08 by grudler           #+#    #+#             */
/*   Updated: 2019/09/05 15:39:10 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void		init_mlx(t_mlx *mlx)
{
	if ((mlx->ptr = mlx_init()) == NULL)
		ft_error();
	if ((mlx->win_ptr = mlx_new_window(mlx->ptr, 1200, WINY, "fractol"))
		== NULL)
		ft_error();
	if ((mlx->i.img = mlx_new_image(mlx->ptr, 1200, WINY)) == NULL)
		ft_error();
	mlx->i.canvas = mlx_get_data_addr(mlx->i.img, &mlx->i.bpp,
		&mlx->i.size_line, &mlx->i.endian);
}

int			ft_which_frac(char **argv, t_mlx *mlx)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mlx->fract = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		mlx->fract = 1;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		mlx->fract = 2;
	else if (ft_strcmp(argv[1], "burningjulia") == 0)
		mlx->fract = 3;
	else
	{
		ft_putstr("Error_name\n Usage :\n /fractol mandelbrot\n /fractol ");
		ft_putstr("julia\n /fractol burningship\n /fractol burningjulia\n");
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		if (ft_which_frac(argv, &mlx) == 0)
			return (0);
		init_mlx(&mlx);
		init_var(&mlx);
		mlx_loop_hook(mlx.ptr, multi_thread, &mlx);
		mlx_hook(mlx.win_ptr, MOTION_NOTIFY, 0, motion_notify, &mlx);
		mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
		mlx_hook(mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
		mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
	{
		ft_putstr("Need one and only one argument\n Usage :\n ");
		ft_putstr("/fractol mandelbrot\n /fractol julia\n /fractol ");
		ft_putstr("burningship\n /fractol burningjulia\n");
	}
	return (0);
}
