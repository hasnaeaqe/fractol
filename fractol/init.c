/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:58:54 by haqajjef          #+#    #+#             */
/*   Updated: 2025/03/11 13:57:38 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialisation(t_fractol *fract)
{
	fract->mlx_ptr = mlx_init();
	if (!fract->mlx_ptr)
		exit(EXIT_FAILURE);
	fract->mlx_win = mlx_new_window(fract->mlx_ptr, 800, 800, fract->name);
	if (!fract->mlx_win)
		exit(EXIT_FAILURE);
	fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, 800, 800);
	if (!fract->img.img_ptr)
		exit(EXIT_FAILURE);
	fract->img.addr = mlx_get_data_addr(fract->img.img_ptr,
			&fract->img.bits_per_pixel, &fract->img.size_line,
			&fract->img.endian);
	if (!fract->img.addr)
		exit(EXIT_FAILURE);
	fract->zoom = 1.0;
	fract->iters = 240;
}

double	screen_to_complex(double x, double max, double min, double size_screen)
{
	double	range;
	double	scale;

	range = max - min;
	scale = range / size_screen;
	return (min + x * scale);
}

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*adr;

	if (x > 0 && x <= 800 && y > 0 && y <= 800)
	{
		adr = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
		*(unsigned int *)adr = color;
	}
}

int	close_win(t_fractol *fract)
{
	mlx_destroy_image(fract->mlx_ptr, fract->img.img_ptr);
	mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_fractol *fract)
{
	if (keycode == 53)
		close_win(fract);
	return (0);
}
