/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 05:33:29 by jcremin           #+#    #+#             */
/*   Updated: 2019/05/03 16:57:24 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	char i;

	i = (char)c;
	if (c >= 'A' && c <= 'Z')
		return ((int)(c + 32));
	return ((int)c);
}
