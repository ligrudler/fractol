/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:47:28 by grudler           #+#    #+#             */
/*   Updated: 2019/07/09 19:04:04 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx.h"

# define WINX 1090
# define WINY 720

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;

	void		*img;
	char		*canvas;
	int			bpp;
	int			size_line;
	int			endian;

	int			fract;

	int			x;
	int			y;
	int			it;
	double		x1;
	double		y1;
	int			color;
	double		c_i;
	double		c_r;
	double		z_i;
	double		z_r;
	int			it_max;
	double		zoom;
}				t_mlx;

int				mandelbrot(void *param);
void			put_pixel(t_mlx *mlx);
int				ft_which_frac(char **argv, t_mlx *mlx);