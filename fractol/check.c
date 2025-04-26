/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:33:56 by haqajjef          #+#    #+#             */
/*   Updated: 2025/03/04 17:10:42 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_num(char *nb)
{
	int	i;
	int	count_point;

	count_point = 0;
	i = 0;
	if (nb[i] == '+' || nb[i] == '-')
		i++;
	while (nb[i])
	{
		if (nb[i] == '.')
		{
			if (count_point == 0 && nb[i + 1] != '\0' && ft_isdigit(nb[i + 1]))
				count_point++;
			else
				return (0);
		}
		else if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_double(char *nb)
{
	double	val;

	val = ft_atod(nb);
	return (val >= -2.0 && val <= 2.0);
}
