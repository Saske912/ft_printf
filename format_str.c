/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:27:27 by pfile             #+#    #+#             */
/*   Updated: 2020/07/08 20:48:27 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

void	print_h(unsigned long long nb, char s)
{
	if (nb > 15)
		print_h(nb / 16, s);
	hex_spam(nb, s);
}

t_conf	format_percent(t_conf config)
{
	if (config.left)
		config.printed_len += putchar_int(37);
	if (config.wide)
		while (config.wide-- - 1)
		{
			if (config.zero && !config.left)
				config.printed_len += putchar_int(48);
			else
				config.printed_len += putchar_int(32);
		}
	if (!config.left)
		config.printed_len += putchar_int(37);
	return (config);
}

t_conf	format_char(char c, t_conf config)
{
	if (config.left)
		config.printed_len += putchar_int(c);
	if (config.wide)
	{
		(config.wide)--;
		while (config.wide--)
			config.printed_len += putchar_int(32);
	}
	if (!config.left)
		config.printed_len += putchar_int(c);
	return (config);
}

t_conf	format_string(char *str, t_conf config)
{
	int		b;

	b = 0;
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		b = 1;
	}
	if (config.left)
		config = format_form(str, config);
	if (config.wide)
		config = format_wide(str, config);
	if (!config.left)
		config = format_form(str, config);
	if (b)
		free(str);
	return (config);
	if (config.precision < 0 || !config.zero)
		config.precision = mod(config.precision);
}

t_conf	converse_struct(t_conf config, va_list args)
{
	if (config.format == 37)
		config = format_percent(config);
	else if (config.format == 99)
		config = format_char(va_arg(args, int), config);
	else if (config.format == 115)
		config = format_string(va_arg(args, char *), config);
	else if (config.format == 112)
		config = save_pointer(va_arg(args, unsigned long long), config);
	else if (config.format == 100 || config.format == 105)
		config = format_int(va_arg(args, int), config);
	else if (config.format == 120 || config.format == 88)
		config = print_hex(va_arg(args, unsigned int), config);
	else if (config.format == 117)
		config = format_ui(va_arg(args, unsigned int), config);
	return (config);
}
