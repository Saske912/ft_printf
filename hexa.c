/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:21:04 by pfile             #+#    #+#             */
/*   Updated: 2020/07/08 20:30:43 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

t_conf	decimal_h(unsigned int nb, t_conf config)
{
	unsigned int	len;
	int				k;

	len = nb;
	k = 1;
	while (len /= 16)
		k++;
	print_hh(nb, config.format);
	config.printed_len += k;
	return (config);
}

int		hex_s(unsigned int nb, char s)
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

t_conf	charge_hex(unsigned int mem, t_conf config)
{
	int		i;

	i = config.added_len;
	if (config.precision > config.added_len)
		while (i++ < config.precision)
			config.printed_len += putchar_int(48);
	if (!mem && config.point && ((config.wide && config.wide <\
					config.precision) || !config.precision))
		config.printed_len += putchar_int(32);
	else
		config = decimal_h(mem, config);
	return (config);
}

t_conf	print_hex(unsigned int mem, t_conf config)
{
	unsigned int k;

	if (!mem && config.point && !config.precision && !config.wide)
		return (config);
	k = mem;
	config.added_len = 1;
	while (k /= 16)
		config.added_len++;
	if (config.left)
		config = charge_hex(mem, config);
	if (config.wide)
	{
		config = int_wide(config);
	}
	if (!config.left)
		config = charge_hex(mem, config);
	return (config);
}
