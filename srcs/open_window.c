/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:10:45 by taegon-i          #+#    #+#             */
/*   Updated: 2019/08/19 20:10:39 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"
#include <math.h>
#include <unistd.h>

void		function(int i, int j, t_fdf *fdf)
{
	fdf->rotate_z1 = fdf->image[j][i].z * fdf->factor * fdf->z_change;
	fdf->rotate_x1 = fdf->center_x + i * (fdf->factor);
	fdf->rotate_y1 = fdf->center_y + j * (fdf->factor);
	rotate(fdf);
	fdf->image[j][i].x = fdf->rotate_x1 + fdf->start_x;
	fdf->image[j][i].y = fdf->rotate_y1 + fdf->start_y;
	if (i > 0)
	{
		drawline(fdf->image[j][i],
			fdf->image[j][i - 1],
			fdf);
	}
	if (j > 0)
	{
		drawline(fdf->image[j][i],
			fdf->image[j - 1][i],
			fdf);
	}
}

void		arr_black(t_fdf *fdf)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (k < 1080)
	{
		while (l < 1920)
		{
			fdf->img->arr[k * 1920 + l] = 0x000000;
			l++;
		}
		l = 0;
		k++;
	}
}

int			re_draw(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	fdf->start_x = 0;
	fdf->start_y = 0;
	fdf->center_x = 1920 / 2;
	fdf->center_y = 1080 / 2;
	arr_black(fdf);
	start_cord(fdf);
	while (j < fdf->row)
	{
		while (i < fdf->column)
		{
			function(i, j, fdf);
			i++;
		}
		j++;
		i = 0;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
			fdf->img->img_ptr, 0, 0);
	description(fdf);
	return (0);
}

int			open_window(t_fdf *fdf)
{
	if (fdf->row > 50 || fdf->column > 50)
		fdf->factor = 1;
	else
		fdf->factor = 20;
	fdf->x_alpha = -0.52;
	fdf->y_beta = -0.52;
	fdf->z_gamma = 0.52;
	re_draw(fdf);
	return (0);
}
