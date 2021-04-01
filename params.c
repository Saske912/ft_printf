/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 04:56:28 by pfile             #+#    #+#             */
/*   Updated: 2020/07/08 01:25:10 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

int		get_config(char s)
{
	return (s == 45 || s == 42 || (s > 47 && s < 58) || s == 46);
}

int		format(char s)
{
	return (s == 99 || s == 115 || s == 112 || s == 100 ||\
			s == 37 || s == 105 || s == 117 || s == 120 || s == 88);
}

char	get_format(const char *str, t_conf param)
{
	while (get_config(str[param.input_len]))
		(param.input_len)++;
	param.format = str[param.input_len];
	return (param.format);
}

int		is_parametr(const char *str, int len_str)
{
	while (get_config(str[len_str]))
		len_str++;
	return (format(str[len_str]));
}

int		putchar_int(char c)
{
	ft_putchar(c);
	return (1);
}
