/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:47:28 by grudler           #+#    #+#             */
/*   Updated: 2019/09/02 13:28:39 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx.h"
#include "keycode.h"
#include <pthread.h>
#include <math.h>
#include "colorcode.h"
#include <stdio.h>

# define WINX 800
# define WINY 800
# define WINALL 1200
# define ZOOM 250
# define NBR_THREAD 2
# define WIN_THREAD 400

typedef struct	s_img
{
	void		*img;
	char		*canvas;

	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_mouse
{
	int			x;
	int			y;
	double		j_y;
	double		j_x;
	int			tmpx;
	int			tmpy;
	int			mousebutton;
	char		mouseboard[5];
}				t_mouse;

typedef struct	s_color
{
	int			palette[16];
	int			chgcolor;
	int			gradient;

	double		end;
	int			color;
}				t_color;

typedef struct	s_algo
{
	int			x;
	int			y;

	int			it;
	int			it_max;

	double		x1;
	double		y1;
	double		c_i;
	double		c_r;
	double		z_i;
	double		z_r;

	int			y_max;
	double		zoom;
	double		temp;
}				t_algo;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;

	int			fract;
	char		keyboard[512];
	int			stop;
	
	t_algo		a;
	t_img		i;
	t_color		clr;
	t_mouse		m;
}				t_mlx;

typedef struct	s_leg
{
	char		zoom[128];
	char		deg[100];
}				t_leg;

int				ft_which_frac(char **argv, t_mlx *mlx);

void			*mandelbrot(void *param);
void			*julia(void *param);
void			*burning(void *param);

int				multi_thread(t_mlx *pmlx);
void			put_pixel_to_img(t_mlx *mlx, int color, int x, int y);
void			draw_fract(t_mlx *mlx);

int				key_press(int key, void *param);
int				key_release(int key, void *param);
void			init_key(t_mlx *mlx);

void			init_var(t_mlx *pmlx);

int				print_legend(t_mlx *mlx);
void			fill_palette(t_mlx *mlx);

int				mouse_hook(int button, int x, int y, void *param);
void			zoom_dezoom(int button, int x, int y, t_mlx *mlx);
int				motion_notify(int x, int y, void *param);

void			color_box_legend(t_mlx *mlx);
void			draw_little_square(t_mlx *mlx);
void			first_step(t_mlx *mlx);
int				get_color(t_mlx *mlx);
void			print_name(t_mlx *mlx);

void			*autre(void *param);



