/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:06:24 by jcremin           #+#    #+#             */
/*   Updated: 2019/07/23 14:48:57 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		char_is_base(char c, int base)
{
	char	*string;
	int		i;

	string = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (string[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int		prefix(const char *str, int base)
{
	size_t i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (1);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (1);
}

int		ft_atoi_base(const char *str, int base)
{
	unsigned long	res;
	size_t			i;
	int				neg;

	res = 0;
	i = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !prefix(&str[i], base))
		return (0);
	if (base == 2 || base == 16)
		i = i + 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		neg = (str[i] == '-') ? -1 : 1;
	while (char_is_base(str[i], base) >= 0)
		res = res * base + char_is_base(str[i++], base);
	return ((int)(res * neg));
}
