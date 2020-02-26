/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:14:38 by jcremin           #+#    #+#             */
/*   Updated: 2019/08/20 11:20:57 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "mlx.h"

typedef struct			s_pixel
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_pixel;

typedef struct			s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct			s_img
{
	void				*img_ptr;
	char				*img_data;
	int					bpp;
	int					size_line;
	int					endian;
	int					*arr;
}						t_img;

typedef struct			s_fdf
{
	int					valid;
	int					z_change;
	int					row;
	int					column;
	int					last_column;
	int					center_x;
	int					center_y;
	char				*buf;
	int					color;
	t_img				*img;
	t_pixel				**image;
	void				*mlx_ptr;
	void				*win_ptr;
	t_mouse				*mouse;
	int					factor;
	double				x_alpha;
	double				y_beta;
	double				z_gamma;
	int					rotate_x1;
	int					rotate_y1;
	int					rotate_z1;
	int					rotate_x2;
	int					rotate_y2;
	int					start_x;
	int					start_y;
}						t_fdf;

t_pixel					**ft_ctdas(float row, float column);
t_pixel					**was(t_fdf fdf);
int						counter_column(char *buf);
int						open_window(t_fdf *fdf);
void					drawline(t_pixel e, t_pixel s, t_fdf *fdf);
int						press_button(t_fdf *fdf);
int						re_draw(t_fdf *fdf);
void					description(t_fdf *fdf);
int						close_win(void *param);
int						key_press(int keycode, void *param);
int						mouse_press(int keycode, int x, int y, void *param);
int						mouse_release(int button, int x, int y, void *param);
int						mouse_move(int x, int y, void *param);
void					rotate(t_fdf *fdf);
int						start_cord(t_fdf *fdf);
int						get_color(t_pixel current, t_pixel start,
						t_pixel end, t_pixel delta);
void					creat_win(t_fdf *fdf);
void					free_strsplit(char **mass);
void					run_gnl_1(int fd, t_fdf *fdf);
void					run_gnl_2(int fd, t_fdf *fdf);
int						min_nemin(char min);
void					z_change(int keycode, t_fdf *fdf);
int						usage(int argc, char **argv, int fd);

#endif
