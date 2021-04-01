/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:33:42 by pfile             #+#    #+#             */
/*   Updated: 2020/07/08 20:39:02 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

t_conf	base_struct(int a, int b)
{
	t_conf	config;

	config.zero = 0;
	config.left = 0;
	config.wide = 0;
	config.point = 0;
	config.precision = 0;
	config.format = 0;
	config.added_len = 0;
	config.input_len = a;
	config.printed_len = b;
	return (config);
}

t_conf	fill_struct(t_conf config, va_list args, const char *str)
{
	while (get_config(str[config.input_len]))
	{
		if (str[config.input_len] == 45 && !config.left && !config.zero)
			config.left = 1;
		if (str[config.input_len] == 46 && !config.point)
			config.point = 1;
		if (str[config.input_len] == 48 && !config.zero && !config.point)
			config.zero = 1;
		if (str[config.input_len] > 48 && str[config.input_len] < 58)
			config = fill_numbers(str, config);
		if (str[config.input_len] == 42)
			config = fill_args(config, args);
		(config.input_len)++;
	}
	(config.input_len)++;
	return (config);
}

int		print_str(va_list args, const char *str)
{
	t_conf	config;

	config.input_len = 0;
	config.printed_len = 0;
	while (str[config.input_len])
	{
		if (str[config.input_len] == 37)
		{
			config = base_struct(config.input_len, config.printed_len);
			(config.input_len)++;
			if (is_parametr(str, config.input_len))
			{
				config.format = get_format(str, config);
				config = fill_struct(config, args, str);
				config = converse_struct(config, args);
			}
		}
		if (str[config.input_len] && str[config.input_len] != 37)
		{
			ft_putchar(str[(config.input_len)++]);
			(config.printed_len)++;
		}
	}
	return (config.printed_len);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	if (!str)
		return (-1);
	va_start(args, str);
	len = print_str(args, str);
	va_end(args);
	return (len);
}
