/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:17:08 by jcremin           #+#    #+#             */
/*   Updated: 2019/05/03 16:44:59 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s1;

	s1 = (unsigned char*)s;
	while (n)
	{
		if (*s1 == (unsigned char)c)
		{
			return (s1);
		}
		n--;
		s1++;
	}
	return (NULL);
}
