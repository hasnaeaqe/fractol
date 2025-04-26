/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:35:31 by haqajjef          #+#    #+#             */
/*   Updated: 2025/03/15 12:23:34 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_hook(int button, int x, int y, t_fractol *fract)
{
	(void) x;
	(void) y;
	if (button == 4)
		fract->zoom *= 1.1;
	else if (button == 5)
		fract->zoom /= 1.1;
	else
		return (0);
	draw_fractal(fract);
	return (0);
}

static int	parse_args(t_fractol *fract, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		fract->name = "mandelbrot";
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
		{
			write(2, "Error: Julia requires 2 numeric arguments\n", 43);
			return (1);
		}
		if (!is_num(argv[2]) || !is_num(argv[3])
			|| !valid_double(argv[2]) || !valid_double(argv[3]))
		{
			write(2, "Error: Invalid Julia arguments\n", 32);
			return (1);
		}
		fract->name = "julia";
		fract->julia_real = ft_atod(argv[2]);
		fract->julia_imaginar = ft_atod(argv[3]);
	}
	else
	{
		write(1, "Error: Unknown fractal type\n", 28);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc <= 1)
		return (0);
	if (parse_args(&fract, argc, argv) != 0)
		return (1);
	initialisation(&fract);
	draw_fractal(&fract);
	mlx_key_hook(fract.mlx_win, key_press, &fract);
	mlx_mouse_hook(fract.mlx_win, mouse_hook, &fract);
	mlx_hook(fract.mlx_win, 17, 0, close_win, &fract);
	mlx_loop(fract.mlx_ptr);
	return (0);
}
