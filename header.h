/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:34:39 by pfile             #+#    #+#             */
/*   Updated: 2020/07/08 14:59:01 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_conf
{
	int				zero;
	int				left;
	int				wide;
	int				point;
	int				precision;
	char			format;
	int				input_len;
	int				printed_len;
	int				added_len;
}					t_conf;

int					ft_printf(const char *str, ...);
int					get_config(char s);
int					format(char s);
char				get_format(const char *str, t_conf param);
int					is_parametr(const char *str, int len_str);
t_conf				fill_numbers(const char *str, t_conf config);
t_conf				fill_args(t_conf config, va_list args);
t_conf				converse_struct(t_conf config, va_list args);
t_conf				format_percent(t_conf config);
int					putchar_int(char c);
t_conf				format_string(char *str, t_conf config);
t_conf				format_form(char *str, t_conf config);
t_conf				format_precision(char *str, t_conf config);
t_conf				print_precision(char *str, t_conf config);
t_conf				format_wide(char *str, t_conf config);
int					hex_spam(unsigned long long nb, char s);
t_conf				decimal_hex(unsigned long long nb, t_conf config);
t_conf				save_pointer(unsigned long long mem, t_conf config);
t_conf				wide_pointer(t_conf config);
t_conf				print_pointer(unsigned long long mem, t_conf config);
t_conf				format_int(int nb, t_conf config);
t_conf				print_hex(unsigned int mem, t_conf config);
t_conf				int_wide(t_conf config);
t_conf				format_ui(unsigned int nb, t_conf config);
void				print_h(unsigned long long nb, char s);
void				print_hh(unsigned int nb, char s);
int					hex_s(unsigned int nb, char s);

#endif
