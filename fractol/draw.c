/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:43:11 by haqajjef          #+#    #+#             */
/*   Updated: 2025/03/15 12:09:47 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	choix_color(int i, t_fractol fractal)
{
	if (i == fractal.iters)
		return (0x000000);
	else
		return (i * 0x170101);
}

static void	value(t_complex z, t_complex *c, t_fractol *fract)
{
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
	{
		c->re = z.re;
		c->im = z.im;
	}
	else
	{
		c->im = fract->julia_imaginar;
		c->re = fract->julia_real;
	}
}

static void	process_pixel(t_fractol *fract, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.re = screen_to_complex(x, 2, -2, 800) * fract->zoom;
	z.im = screen_to_complex(y, -2, 2, 800) * fract->zoom;
	value(z, &c, fract);
	i = 0;
	while (i < fract->iters && (z.re * z.re + z.im * z.im) < 4)
	{
		z = add_z(pow_z(z), c);
		i++;
	}
	color = choix_color(i, *fract);
	put_pixel(&fract->img, x, y, color);
}

void	draw_fractal(t_fractol *fract)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			process_pixel(fract, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_win,
		fract->img.img_ptr, 0, 0);
}
