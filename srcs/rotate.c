/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:46:43 by taegon-i          #+#    #+#             */
/*   Updated: 2019/08/19 20:10:29 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"
#include <math.h>

static void		rotate_x(int *y, int *z, float alpha)
{
	float		previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void		rotate_y(int *x, int *z, float beta)
{
	float		previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void		rotate_z(int *x, int *y, float gamma)
{
	float		previous_x;
	float		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void			rotate(t_fdf *fdf)
{
	rotate_x(&fdf->rotate_y1, &fdf->rotate_z1, fdf->x_alpha);
	rotate_y(&fdf->rotate_x1, &fdf->rotate_z1, fdf->y_beta);
	rotate_z(&fdf->rotate_x1, &fdf->rotate_y1, fdf->z_gamma);
}
