/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:47:28 by grudler           #+#    #+#             */
/*   Updated: 2019/08/22 19:57:04 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx.h"
#include "keycode.h"
#include "pthread.h"

# define WINX 1200
# define WINY 1200
# define NBR_THREAD 6
# define WIN_THREAD 200

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
	char		keyboard[512];

	int			x;
	int			y;
	int			y_max;
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

void			*mandelbrot(void *param);
int				mandel_thread(t_mlx *pmlx);
void			put_pixel(t_mlx *mlx);
int				ft_which_frac(char **argv, t_mlx *mlx);

int				key_press(int key, void *param);
int				key_release(int key, void *param);
void			init_key(t_mlx *mlx);

void			init_var(t_mlx *pmlx);
void			init_var_julia(t_mlx *pmlx);

int				julia(void *param);

int				mouse_press(int button, int x, int y, void *param);
