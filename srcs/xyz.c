/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:41:49 by jcremin           #+#    #+#             */
/*   Updated: 2019/08/20 11:45:28 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"
#include <math.h>

int		start_cord(t_fdf *fdf)
{
	fdf->rotate_x1 = fdf->center_x;
	fdf->rotate_y1 = fdf->center_y;
	fdf->rotate_z1 = fdf->image[0][0].z * fdf->factor;
	rotate(fdf);
	fdf->rotate_x2 = fdf->rotate_x1;
	fdf->rotate_y2 = fdf->rotate_y1;
	fdf->rotate_x1 = fdf->center_x + (fdf->column - 1) * (fdf->factor);
	fdf->rotate_y1 = fdf->center_y + (fdf->row - 1) * (fdf->factor);
	fdf->rotate_z1 = fdf->image[fdf->row - 1][fdf->column - 1].z * fdf->factor;
	rotate(fdf);
	fdf->start_x = (fdf->rotate_x1 - fdf->rotate_x2) / 2;
	fdf->start_y = (fdf->rotate_y1 - fdf->rotate_y2) / 2;
	fdf->start_x = fdf->center_x - fdf->start_x - fdf->rotate_x2;
	fdf->start_y = fdf->center_y - fdf->start_y - fdf->rotate_y2;
	return (0);
}

void	creat_win(t_fdf *fdf)
{
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1920, 1080, "SuperMegaTeamPro");
	fdf->image = ft_ctdas(fdf->row, fdf->column);
	fdf->row = 0;
}

int		usage(int argc, char **argv, int fd)
{
	if (argc != 2)
	{
		write(1, "USAGE: ./fdf filename.fdf\n", 26);
		return (0);
	}
	if (ft_strstr(argv[1], ".fdf\0") == 0)
	{
		if (ft_strstr(argv[1], ".FDF\0") != 0)
			return (1);
		write(1, "This is not MAP\n", 16);
		return (0);
	}
	if (fd < 0)
	{
		write(1, "MAP not found\n", 14);
		return (0);
	}
	return (1);
}

int		min_nemin(char min)
{
	int minus;

	minus = 1;
	if (min == 45)
		minus = -1;
	return (minus);
}

void	z_change(int keycode, t_fdf *fdf)
{
	if (keycode == 30)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->z_change += 1;
		re_draw(fdf);
	}
	if (keycode == 33)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->z_change -= 1;
		re_draw(fdf);
	}
}
