/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:00:30 by pfile             #+#    #+#             */
/*   Updated: 2020/07/07 18:55:16 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_conf	decimal_hex(unsigned long long nb, t_conf config)
{
	int					i;
	unsigned long long	len;
	int					k;

	len = nb;
	k = 1;
	while (len /= 16)
		k++;
	if (config.precision && config.point && !nb && config.format == 112)
	{
		i = config.precision;
		while (i--)
			config.printed_len += putchar_int(48);
		return (config);
	}
	print_h(nb, config.format);
	config.printed_len += k;
	return (config);
}

int		hex_spam(unsigned long long nb, char s)
{
	if ((nb % 16) > 9)
	{
		if (s == 88)
			putchar_int((nb % 16) + 55);
		else
			putchar_int((nb % 16) + 87);
	}
	else
		putchar_int((nb % 16) + 48);
	return (1);
}

t_conf	print_pointer(unsigned long long mem, t_conf config)
{
	config.printed_len += putchar_int(48);
	config.printed_len += putchar_int(120);
	return (decimal_hex(mem, config));
}

t_conf	wide_pointer(t_conf config)
{
	if (config.precision)
		config.added_len += config.precision - 1;
	if (config.wide > config.added_len)
		while (config.added_len++ < config.wide)
			config.printed_len += putchar_int(32);
	config.added_len = 0;
	return (config);
}

t_conf	save_pointer(unsigned long long mem, t_conf config)
{
	unsigned long long	k;

	k = mem;
	config.added_len = 3;
	while (k /= 16)
		config.added_len++;
	if (config.left)
		config = print_pointer(mem, config);
	if (config.wide)
		config = wide_pointer(config);
	if (!config.left)
		config = print_pointer(mem, config);
	return (config);
}
