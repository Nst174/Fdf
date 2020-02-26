/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:12:22 by taegon-i          #+#    #+#             */
/*   Updated: 2019/08/19 20:11:18 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

void			drawline(t_pixel e, t_pixel s, t_fdf *fdf)
{
	t_pixel		d[3];
	int			error[2];

	d[0].x = abs(s.x - e.x);
	d[0].y = abs(s.y - e.y);
	d[1].x = e.x < s.x ? 1 : -1;
	d[1].y = e.y < s.y ? 1 : -1;
	d[2] = e;
	error[0] = d[0].x - d[0].y;
	while (d[2].x != s.x || d[2].y != s.y)
	{
		if (d[2].y > 0 && d[2].y < 1080 && d[2].x > 0 && d[2].x < 1920)
			fdf->img->arr[d[2].y * 1920 + d[2].x] = get_color(d[2], e, s, d[0]);
		error[1] = error[0] * 2;
		if (error[1] > -d[0].y)
		{
			error[0] -= d[0].y;
			d[2].x += d[1].x;
		}
		if (error[1] < d[0].x)
		{
			error[0] += d[0].x;
			d[2].y += d[1].y;
		}
	}
}
