/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:14:09 by jcremin           #+#    #+#             */
/*   Updated: 2019/08/19 20:10:24 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

void		free_strsplit(char **mass)
{
	int		i;

	i = 0;
	while (mass[i])
		free(mass[i++]);
	free(mass);
}

void		run_gnl_2(int fd, t_fdf *fdf)
{
	while (get_next_line(fd, &fdf->buf) == 1)
	{
		was(*fdf);
		free(fdf->buf);
		fdf->row++;
	}
}

void		run_gnl_1(int fd, t_fdf *fdf)
{
	fdf->row = 0;
	while (get_next_line(fd, &fdf->buf) == 1)
	{
		if (fdf->row > 0)
			fdf->last_column = fdf->column;
		fdf->column = counter_column(fdf->buf);
		if ((fdf->column != fdf->last_column) && fdf->row > 0)
		{
			fdf->valid = 0;
		}
		fdf->row++;
		free(fdf->buf);
	}
}

int			counter_column(char *buf)
{
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] >= 48 && buf[i] <= 57)
		{
			counter++;
			while (buf[i] != ' ' && buf[i] != '\0')
				i++;
		}
		if (buf[i] != '\0')
			i++;
	}
	return (counter);
}
