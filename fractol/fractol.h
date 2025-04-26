/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:18:12 by haqajjef          #+#    #+#             */
/*   Updated: 2025/03/16 15:51:50 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	double		zoom;
	int			iters;
	void		*mlx_ptr;
	void		*mlx_win;
	t_image		img;
	char		*name;
	double		julia_real;
	double		julia_imaginar;
}	t_fractol;

int			is_num(char *nb);
int			valid_double(char *nb);
int			ft_strcmp(const char *s1, const char *s2);
double		ft_atod(char *nb);
t_complex	pow_z(t_complex z);
t_complex	add_z(t_complex z, t_complex c);
void		initialisation(t_fractol *fract);
double		screen_to_complex(double x, double max,
				double min, double size_screen);
void		put_pixel(t_image *img, int x, int y, int color);
void		draw_fractal(t_fractol *fract);
int			close_win(t_fractol *fract);
int			key_press(int keycode, t_fractol *fract);

#endif