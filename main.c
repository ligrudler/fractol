/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:56:08 by grudler           #+#    #+#             */
/*   Updated: 2019/07/09 23:49:43 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_mlx *mlx)
{
	*(int *)&mlx->canvas[mlx->y * mlx->size_line + mlx->x * 4] = mlx->color * mlx->it;
}

int	ft_which_frac(char **argv, t_mlx *mlx)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mlx->fract = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		mlx->fract = 1;
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
		if ((mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WINX, WINY, "fractol")) == NULL)
			ft_error();
		if ((mlx.img = mlx_new_image(mlx.mlx_ptr, WINX, WINY)) == NULL)
			ft_error();
		mlx.zoom = 150;
		mlx.canvas = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);
		mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
		mlx_hook(mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
		if (mlx.fract == 0)
			mlx_loop_hook(mlx.mlx_ptr, mandelbrot, &mlx);
		if (mlx.fract == 1)
			mlx_loop_hook(mlx.mlx_ptr, julia, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\" wesh");
	return (0);
}
