/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:47:28 by grudler           #+#    #+#             */
/*   Updated: 2019/10/15 15:42:51 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include "keycode.h"
# include "colorcode.h"
# include <pthread.h>
# include <math.h>
# include <stdio.h>

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
	int			dec;
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
	char		deg[128];
}				t_leg;

typedef struct	s_mlx
{
	void		*ptr;
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

/*
** main.c
*/

int				ft_which_frac(char **argv, t_mlx *mlx);
void			init_mlx(t_mlx *mlx);

/*
** mandelbrot.c
*/

void			*mandelbrot(void *param);
void			mandel_calc(t_mlx *mlx);

/*
** juia.c
*/

void			*julia(void *param);
void			julia_calc(t_mlx *pmlx);

/*
** burningship.c
*/

void			*burning(void *param);
void			burning_calc(t_mlx *pmlx);

/*
** burningjulia.c
*/

void			*burningjulia(void *param);
void			burningjulia_calc(t_mlx *pmlx);

/*
** color.c
*/

void			set_color1(t_mlx *mlx);
void			set_color2(t_mlx *mlx);
void			set_color3(t_mlx *mlx);
void			set_color4(t_mlx *mlx);
void			fill_palette(t_mlx *mlx);

/*
** grad_color.c
*/

int				get_color(t_mlx *mlx);
double			get_light(int start, int end, double percent);
double			get_percent(int start, int end, int current);

/*
** init_var.c
*/

void			init_var(t_mlx *pmlx);
void			init_all(t_mlx *pmlx);

/*
** key_handler.c
*/

void			init_key(t_mlx *mlx);
void			key_move(t_mlx *mlx);
int				key_release(int key, void *param);
int				key_press(int key, void *param);

/*
** mouse_handler.c
*/

int				mouse_hook(int button, int x, int y, void *param);
void			set_menu(int x, int y, t_mlx *mlx);
void			change_color(int x, int y, t_mlx *mlx);
void			change_color(int x, int y, t_mlx *mlx);
int				motion_notify(int x, int y, void *param);

/*
** multithread.c
*/

int				multi_thread(t_mlx *pmlx);
void			create_thread(t_mlx *pmlx);
void			first_step(t_mlx *mlx);

/*
** leg_background.c
*/

void			print_name(t_mlx *mlx);
void			color_box_legend(t_mlx *mlx);
void			draw_little_square(t_mlx *mlx);

/*
** legend.c
*/

int				print_legend(t_mlx *mlx);
void			print_menu(t_mlx *mlx);
void			menu_gradient(t_leg leg, t_mlx *mlx);
void			print_var(t_mlx *mlx);

/*
** utils.c
*/

void			clean_mlx(t_mlx *mlx, int idx);
void			decalage_palette(t_mlx *mlx);
void			put_pixel_to_img(t_mlx *mlx, int color, int x, int y);

#endif
