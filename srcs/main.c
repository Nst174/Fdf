/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:01:08 by taegon-i          #+#    #+#             */
/*   Updated: 2019/08/20 11:18:29 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

int			func_in_was(int i, int j, t_fdf fdf)
{
	int		r;
	int		min;

	min = min_nemin(fdf.buf[i - 1]);
	fdf.image[(int)fdf.row][j].z = ft_getnbr(&fdf.buf[i]) * min;
	fdf.image[(int)fdf.row][j].x = fdf.row;
	fdf.image[(int)fdf.row][j].y = j;
	r = fdf.image[(int)fdf.row][j].z;
	while (r / 10 != 0)
	{
		r = r / 10;
		i++;
	}
	return (i);
}

void		func_in_was2(int i, int j, t_fdf fdf, char **mass)
{
	mass = ft_strsplit(&fdf.buf[i + 1], ',');
	fdf.image[(int)fdf.row][j].color = ft_atoi_base(mass[0], 16);
	free_strsplit(mass);
}

t_pixel		**was(t_fdf fdf)
{
	int		i;
	int		j;
	char	**mass;

	j = 0;
	i = 0;
	mass = NULL;
	while (fdf.buf[i] != '\0')
	{
		if (fdf.buf[i] >= 48 && fdf.buf[i] <= 57)
		{
			i = func_in_was(i, j, fdf);
			if (fdf.buf[i + 1] == ',')
			{
				func_in_was2(i, j, fdf, mass);
				while ((fdf.buf[i] != ' ') && fdf.buf[i + 1] != '\0')
					i++;
			}
			else
				fdf.image[(int)fdf.row][j].color = 0xFFFFFF;
			j++;
		}
		i++;
	}
	return (fdf.image);
}

void		open_mlx(t_fdf fdf)
{
	fdf.img->size_line = 1920 * 4;
	fdf.img->endian = 0;
	fdf.img->bpp = 32;
	fdf.img->img_ptr = mlx_new_image(fdf.mlx_ptr, 1920, 1080);
	fdf.img->img_data = mlx_get_data_addr(fdf.img->img_ptr,
			&fdf.img->bpp, &fdf.img->size_line, &fdf.img->endian);
	fdf.img->arr = (int*)fdf.img->img_data;
}

int			main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;

	fdf.valid = 1;
	fdf.mlx_ptr = mlx_init();
	fd = open(argv[1], O_RDONLY);
	if (usage(argc, argv, fd) == 0)
		return (0);
	fdf.z_change = 1;
	run_gnl_1(fd, &fdf);
	creat_win(&fdf);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	run_gnl_2(fd, &fdf);
	if (fdf.valid == 0)
	{
		write(1, "Map error\n", 10);
		return (0);
	}
	close(fd);
	open_mlx(fdf);
	open_window(&fdf);
	press_button(&fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
