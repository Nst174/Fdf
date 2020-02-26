/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:37:22 by jcremin           #+#    #+#             */
/*   Updated: 2019/01/12 16:02:41 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}
