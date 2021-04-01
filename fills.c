/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fills.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 20:10:32 by pfile             #+#    #+#             */
/*   Updated: 2020/07/08 21:15:50 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

t_conf	fill_numbers(const char *str, t_conf config)
{
	if (!config.point)
		config.input_len += ft_len_int((config.wide =\
					ft_atoi(&str[config.input_len])));
	else
		config.input_len += ft_len_int((config.precision =\
					ft_atoi(&str[config.input_len])));
	return (config);
}

t_conf	fill_args(t_conf config, va_list args)
{
	if (!config.point)
	{
		if ((config.wide = va_arg(args, int)) < 0)
		{
			config.wide = mod(config.wide);
			if (!config.left)
			{
				config.left = 1;
				config.zero = 0;
			}
		}
	}
	else
	{
		config.precision = va_arg(args, int);
		if ((config.format == 100 || config.format == 105) &&\
				!config.wide)
			config.added_len = 1;
		if (config.format == 112)
			config.precision = mod(config.precision);
	}
	return (config);
}
