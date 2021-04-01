/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:57:53 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 12:19:37 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int i;

	i = -1;
	if (str[0] == '\0')
		return (1);
	while (str[++i] != '\0')
		if (str[i] < 32 || str[i] > 126)
			return (0);
	return (1);
}
