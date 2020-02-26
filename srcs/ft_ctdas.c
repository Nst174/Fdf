/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctdas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:57:51 by taegon-i          #+#    #+#             */
/*   Updated: 2019/06/20 11:33:25 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pixel	**ft_ctdas(float row, float column)
{
	t_pixel	**field;
	int		j;

	j = 0;
	field = (t_pixel **)malloc(sizeof(t_pixel *) * row);
	while (j < row)
	{
		field[j] = (t_pixel *)malloc(sizeof(t_pixel) * (column));
		j++;
	}
	return (field);
}
