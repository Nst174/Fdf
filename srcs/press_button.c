/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:11:36 by taegon-i          #+#    #+#             */
/*   Updated: 2019/08/19 20:10:34 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

int	close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	press_button(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_win, fdf);
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win_ptr, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win_ptr, 6, 0, mouse_move, fdf);
	return (0);
}
