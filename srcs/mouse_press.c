/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:58:35 by taegon-i          #+#    #+#             */
/*   Updated: 2019/08/19 20:10:52 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

int			mouse_press(int keycode, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (keycode == 1)
		fdf->mouse->is_pressed = 1;
	if (keycode == 2)
		fdf->mouse->is_pressed = 2;
	if (keycode == 4)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		if (fdf->factor < 1)
			fdf->factor = 1;
		fdf->factor = fdf->factor - 1;
		re_draw(fdf);
	}
	if (keycode == 5)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->factor = fdf->factor + 1;
		re_draw(fdf);
	}
	return (0);
}

int			mouse_release(int keycode, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)keycode;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = 0;
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed == 1)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->y_beta += (x - fdf->mouse->previous_x) * 0.01;
		fdf->x_alpha += (y - fdf->mouse->previous_y) * 0.01;
		re_draw(fdf);
	}
	if (fdf->mouse->is_pressed == 2)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->z_gamma += (y - fdf->mouse->previous_y) * 0.01;
		re_draw(fdf);
	}
	return (0);
}
