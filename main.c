/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:56:08 by grudler           #+#    #+#             */
/*   Updated: 2019/07/09 13:15:10 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
