/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:02:41 by taegon-i          #+#    #+#             */
/*   Updated: 2019/08/19 20:11:24 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

void		description2(t_fdf *fdf, int y)
{
	void	*mlx;
	void	*win;

	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, 15, y += 35, 0xFFFF99, "Projections:");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC, "1) Press I - Isometric;");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC,
												"2) Press R - Parallel;");
	mlx_string_put(mlx, win, 15, y += 35, 0xFFFF99, "How close fdf:");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC, "1) esc;");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC, "2) cross;");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC, "3) press ctrl+C "
	"on terminal;");
}

void		description(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, 870, y += 5, 0x99FF33, "JCREMIN & TAEGON-I");
	mlx_string_put(mlx, win, 65, y += 20, 0xFFFF66, "How it work?");
	mlx_string_put(mlx, win, 15, y += 35, 0xFFFF99, "Scale:");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC, "1) scroll mouse;");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC, "2) + or - ;");
	mlx_string_put(mlx, win, 15, y += 35, 0xFFFF99, "Turn");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC,
			"1) Press W/S - up/down");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC, "2) Press A/D - "
	"left/right");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC,
			"3) Press Q/E - counterclock-wise/clockwise");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC,
			"4) Hold down the left mouse button and move the cursor - x and y");
	mlx_string_put(mlx, win, 57, y += 20, 0xFFFFCC,
			"5) Hold down the right mouse button and move the cursor - z");
	description2(fdf, y);
}
