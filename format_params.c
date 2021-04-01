/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 22:43:31 by pfile             #+#    #+#             */
/*   Updated: 2020/07/07 20:04:30 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

t_conf	format_wide(char *str, t_conf config)
{
	if (config.precision && config.precision > 0)
		config.added_len = (int)ft_strlen(str) < config.precision\
							? (int)ft_strlen(str) : config.precision;
	if (!config.point || config.precision < 0)
		config.added_len = ft_strlen(str);
	while (config.added_len++ < config.wide)
	{
		if (config.format == 115 || !config.zero)
			config.printed_len += putchar_int(32);
		if (config.zero)
			config.printed_len += putchar_int(48);
	}
	config.added_len = 0;
	return (config);
}

t_conf	print_precision(char *str, t_conf config)
{
	int		i;

	i = 0;
	config.added_len = (int)ft_strlen(str) < config.precision\
		? (int)ft_strlen(str) : config.precision;
	while (config.added_len--)
		config.printed_len += putchar_int(str[i++]);
	config.added_len = 0;
	return (config);
}

t_conf	format_precision(char *str, t_conf config)
{
	int		i;

	i = 0;
	if (!config.precision)
		return (config);
	return (print_precision(str, config));
}

t_conf	format_form(char *str, t_conf config)
{
	int		i;

	i = 0;
	if (!config.point || config.precision < 0)
		while (str[i])
			config.printed_len += putchar_int(str[i++]);
	else if (config.point)
		config = format_precision(str, config);
	return (config);
}
