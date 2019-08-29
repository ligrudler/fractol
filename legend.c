 
#include "fractol.h"

void	color_box_legend(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y <= WINALL)
	{
		x = WINX;
		while (x <= WINALL)
		{
			if ((y >= 150 && y <= 400) || y <= 100 || y >= 450)
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x468DB4);
			else if ((y > 100 && y < 150) || (y > 400 && y < 450))
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x191970);
			x++;
		}
		y++;
	}
	y = 470;
	while (y > 469 && y < 490)
	{
		x = 1156;
		while (x > 1155 && x < 1188)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x800000);
			x++;
		}
		y++;
	}
	y = 495;
	while (y > 494 && y < 515)
	{
		x = 1156;
		while (x > 1155 && x < 1188)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0x800000);
			x++;
		}
		y++;
	}
}

void	print_legend(t_mlx *mlx)
{
	color_box_legend(mlx);
	if (mlx->fract == 0)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 0x191970, "MANDELBROT");
	if (mlx->fract == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 0x0000CD, "JULIA");
	if (mlx->fract == 2)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 820, 60, 0x0000CD, "BURNINGSHIP");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 950, 115, 0xFFFFFF, "INFORMATIONS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 960, 415, 0xFFFFFF, "COMMANDS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 470, 0xFFFFFF, "Changer de couleur ? c'est ici =>");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 810, 495, 0xFFFFFF, "Changer de fractale ? c'est ici =>");
}