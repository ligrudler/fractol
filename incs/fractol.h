/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:47:28 by grudler           #+#    #+#             */
/*   Updated: 2019/09/03 20:32:51 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../mlx.h"
#include "keycode.h"
#include <pthread.h>
#include <math.h>
#include "colorcode.h"
#include <stdio.h>

# define WINX 800
# define WINY 800
# define WINALL 1200
# define ZOOM 250
# define NBR_THREAD 80
# define WIN_THREAD (WINX / NBR_THREAD)

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
	int			j;
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

	int			x_max;
	int			y_max;
	double		zoom;
	double		temp;
}				t_algo;

typedef struct	s_leg
{
	char		zoom[128];
	char		deg[100];
}				t_leg;

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
	t_leg		l;
}				t_mlx;

void	autre_calc(t_mlx *mlx);
void		*autre(void *param);
void	burning_calc(t_mlx *pmlx);
void		*burning(void *param);
void		fill_palette(t_mlx *mlx);
double			get_percent(int start, int end, int current);
double			get_light(int start, int end, double percent);
int				get_color(t_mlx *mlx);
void	julia_calc(t_mlx *pmlx);
void		*julia(void *param);
int		key_press(int key, void *param);
int		key_release(int key, void *param);
void	init_key(t_mlx *mlx);
void	draw_little_square(t_mlx *mlx);
void	color_box_legend(t_mlx *mlx);
void	print_name(t_mlx *mlx);
void	print_var(t_mlx *mlx);
void	menu_gradient(t_leg leg, t_mlx *mlx);
void	print_menu(t_mlx *mlx);
int		print_legend(t_mlx *mlx);
void	put_pixel_to_img(t_mlx *mlx, int color, int x, int y);
void	init_mlx(t_mlx *mlx);
int	ft_which_frac(char **argv, t_mlx *mlx);
void	mandel_calc(t_mlx *mlx);
void		*mandelbrot(void *param);
int		motion_notify(int x, int y, void *param);
void	zoom_dezoom(int button, int x, int y, t_mlx *mlx);
void	set_menu(int x, int y, t_mlx *mlx);
int		mouse_hook(int button, int x, int y, void *param);
void	init_all(t_mlx *pmlx);
void	init_var(t_mlx *pmlx);
void	first_step(t_mlx *mlx);
int		multi_thread(t_mlx *pmlx);
