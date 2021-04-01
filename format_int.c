/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:28:57 by pfile             #+#    #+#             */
/*   Updated: 2020/07/08 21:10:35 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_conf	int_wide(t_conf config)
{
	int		count;

	if (config.point)
		count = config.added_len > config.precision ?\
				config.added_len : config.precision;
	else
		count = config.added_len;
	while (count++ < config.wide)
	{
		if (config.zero && !config.precision)
			config.printed_len += putchar_int(48);
		else
			config.printed_len += putchar_int(32);
	}
	return (config);
}

t_conf	precision_int(int nb, t_conf config)
{
	int		i;

	if (nb < 0 && (!config.zero || (config.precision > 0 &&\
				config.wide > config.precision)))
	{
		config.printed_len += putchar_int(45);
		nb = mod(nb);
	}
	if (config.precision >= config.added_len)
	{
		i = config.added_len;
		while (i++ < config.precision)
			config.printed_len += putchar_int(48);
		ft_putnbr(nb);
		config.printed_len += config.added_len;
		return (config);
	}
	if (nb)
	{
		config.printed_len += config.added_len;
		ft_putnbr(nb);
	}
	else
		config.printed_len += putchar_int(32);
	return (config);
}

t_conf	form_int(int nb, t_conf config)
{
	if (config.point)
	{
		if (config.precision < 0 && !config.zero)
			config.precision = 0;
		config = precision_int(nb, config);
	}
	else
	{
		config.printed_len += nb < 0 ? 1 : 0;
		ft_putnbr(nb);
		config.printed_len += config.added_len;
	}
	return (config);
}

t_conf	format_int(int nb, t_conf config)
{
	if (config.precision < 0 && config.added_len == 1 && !nb)
		config.precision = mod(config.precision);
	if (config.point && !config.precision && !nb && !config.wide)
		return (config);
	if (nb < 0 && config.wide)
		config.wide--;
	config.added_len = ft_len_int(nb) + 1;
	if (config.left)
		config = form_int(nb, config);
	if (config.wide)
	{
		if (!(config.precision > 0 && config.wide >\
					config.precision) && config.zero && nb < 0)
		{
			config.printed_len += putchar_int(45);
			nb = mod(nb);
		}
		config = int_wide(config);
	}
	if (!config.left)
		config = form_int(nb, config);
	return (config);
}
