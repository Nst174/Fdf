/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctdac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:20:33 by jcremin           #+#    #+#             */
/*   Updated: 2019/05/03 16:37:58 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_ctdac(int row, int column)
{
	char	**field;
	int		j;

	j = 0;
	field = (char **)malloc(sizeof(char *) * row);
	while (j < row)
	{
		field[j] = (char *)malloc(sizeof(char ) * (column + 1));
		field[j][column] = '\0';
		j++;
	}
	return (field);
}
