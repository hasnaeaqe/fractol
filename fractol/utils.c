/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:33:23 by haqajjef          #+#    #+#             */
/*   Updated: 2025/03/10 15:46:14 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_decimal_part(char *str, int *i)
{
	double	decimal;
	double	factor;

	decimal = 0.0;
	factor = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			decimal += (str[*i] - '0') * factor;
			factor *= 0.1;
			(*i)++;
		}
	}
	return (decimal);
}

double	ft_atod(char *nb)
{
	int		i;
	int		s;
	double	res;
	double	decimal;

	s = 1;
	i = 0;
	res = 0.0;
	decimal = 0.0;
	while (nb[i] == ' ' || nb[i] == '\t')
		i++;
	if (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			s = -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = res * 10.0 + (nb[i] - '0');
		i++;
	}
	decimal = parse_decimal_part(nb, &i);
	return (s * (res + decimal));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

t_complex	pow_z(t_complex z)
{
	t_complex	res;

	res.re = (z.re * z.re) - (z.im * z.im);
	res.im = 2 * z.re * z.im;
	return (res);
}

t_complex	add_z(t_complex z, t_complex c)
{
	t_complex	res;

	res.re = z.re + c.re;
	res.im = z.im + c.im;
	return (res);
}
