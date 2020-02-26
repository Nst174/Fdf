/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:57:20 by taegon-i          #+#    #+#             */
/*   Updated: 2019/08/19 20:11:08 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

void		zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 24)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->factor = fdf->factor + 1;
		re_draw(fdf);
	}
	if (keycode == 27)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		if (fdf->factor < 1)
			fdf->factor = 1;
		fdf->factor = fdf->factor - 1;
		re_draw(fdf);
	}
}

void		rotate_z(int keycode, t_fdf *fdf)
{
	if (keycode == 14)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->z_gamma += 0.01;
		re_draw(fdf);
	}
	if (keycode == 12)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->z_gamma -= 0.01;
		re_draw(fdf);
	}
}

void		izo_and_para(int keycode, t_fdf *fdf)
{
	if (keycode == 15)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->x_alpha = 0;
		fdf->y_beta = 0;
		fdf->z_gamma = 0;
		re_draw(fdf);
	}
	if (keycode == 34)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->x_alpha = -0.52;
		fdf->y_beta = -0.52;
		fdf->z_gamma = 0.52;
		re_draw(fdf);
	}
}

void		rotate_x_y(int keycode, t_fdf *fdf)
{
	if (keycode == 13)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->x_alpha -= 0.01;
		re_draw(fdf);
	}
	if (keycode == 1)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->x_alpha += 0.01;
		re_draw(fdf);
	}
	if (keycode == 2)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->y_beta += 0.01;
		re_draw(fdf);
	}
	if (keycode == 0)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->y_beta -= 0.01;
		re_draw(fdf);
	}
}

int			key_press(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 53)
		close_win((void *)fdf);
	if (keycode == 24 || keycode == 27)
		zoom(keycode, fdf);
	if (keycode == 14 || keycode == 12)
		rotate_z(keycode, fdf);
	if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)
		rotate_x_y(keycode, fdf);
	if (keycode == 15 || keycode == 34)
		izo_and_para(keycode, fdf);
	if (keycode == 30 || keycode == 33)
		z_change(keycode, fdf);
	return (0);
}
