/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 13:02:46 by pfile             #+#    #+#             */
/*   Updated: 2020/07/08 17:48:24 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_len_ui(unsigned int nb)
{
	int		i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

void	print_ui(unsigned int nb)
{
	if (nb > 9)
		print_ui(nb / 10);
	ft_putchar((nb % 10) + 48);
}

t_conf	form_ui(unsigned int nb, t_conf config)
{
	int		i;

	if (config.precision > config.added_len)
	{
		i = config.added_len;
		while (i++ < config.precision)
			config.printed_len += putchar_int(48);
	}
	if (!nb && config.point && ((config.wide && config.wide <\
					config.precision) || !config.precision))
		config.printed_len += putchar_int(32);
	else
	{
		print_ui(nb);
		config.printed_len += config.added_len;
	}
	return (config);
}

t_conf	format_ui(unsigned int nb, t_conf config)
{
	if (config.point && !config.precision && !nb && !config.wide)
		return (config);
	config.added_len = ft_len_ui(nb);
	if (config.left)
		config = form_ui(nb, config);
	if (config.wide)
		config = int_wide(config);
	if (!config.left)
		config = form_ui(nb, config);
	return (config);
}
