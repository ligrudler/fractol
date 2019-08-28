/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudler <grudler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:47:28 by grudler           #+#    #+#             */
/*   Updated: 2019/08/28 16:52:35 by grudler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx.h"
#include "keycode.h"
#include "pthread.h"
#include "math.h"

# define WINX 800
# define WINY 800
# define WINALL 1200
# define NBR_THREAD 4
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
	double		temp;

	int		palette[16];
}				t_mlx;

void			*mandelbrot(void *param);
int				mandel_thread(t_mlx *pmlx);
void			put_pixel_to_img(t_mlx *mlx, int color);
int				ft_which_frac(char **argv, t_mlx *mlx);
void			draw_fract(t_mlx *mlx);

int				key_press(int key, void *param);
int				key_release(int key, void *param);
void			init_key(t_mlx *mlx);

void			init_var(t_mlx *pmlx);
void			init_var_julia(t_mlx *pmlx);

void			*julia(void *param);
int				julia_thread(t_mlx *pmlx);

int				burning_thread(t_mlx *pmlx);
void			*burning(void *param);
void			burning_calc(t_mlx *pmlx);
void			init_var_burning(t_mlx *pmlx);

void			print_legend(t_mlx *mlx);
void			fill_palette(t_mlx *mlx);


int				mouse_press(int button, int x, int y, void *param);

# define JULIABROT_0		0x19071A
# define JULIABROT_1		0x09012F
# define JULIABROT_2		0x040449
# define JULIABROT_3		0x000764
# define JULIABROT_4		0x0C2C8A
# define JULIABROT_5		0x1852B1
# define JULIABROT_6		0x397DD1
# define JULIABROT_7		0x86B5E5
# define JULIABROT_8		0xD3ECF8
# define JULIABROT_9		0xF1E9BF
# define JULIABROT_10		0xF8C95F
# define JULIABROT_11		0xFFAA00
# define JULIABROT_12		0xCC8000
# define JULIABROT_13		0x995700
# define JULIABROT_14		0x6A3403
# define JULIABROT_15		0x421E0F
