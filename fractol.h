/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:11:41 by del-yaag          #+#    #+#             */
/*   Updated: 2023/12/03 14:44:52 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libc.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define NUM_ITR 400.0
# define ZOOM 1.1

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	char		*type;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	double		left_right;
	double		top_down;
	double		f_const;
	double		s_const;
	int			p_color;
	char		*color;
	int			c_itr;
	int			set_color;
}	t_data;

double		ft_atof(const char *str);
void		how_to_pass_param(void);
int			juliaset(long double x, long double y,
				long double comp_one, long double comp_two);
void		draw_juliaset(t_data *data, int destroy,
				long double comp_one, long double comp_two);
void		draw_mandlbrotset(t_data *data, int destroy);
int			mandlbrotset(long double x, long double y);
int			destroy(t_data *data);
int			key_move(int keycode, t_data *data);
int			mouse_zoom(int mousecode, int x, int y, t_data *data);
int			ft_strcmp(const char *s1, const char *s2);
void		palette_one(t_data *data);
void		palette_org(t_data *data);
void		palette_cos(t_data *data);
void		palette_two(t_data *data);
void		change_color(t_data *data);
void		palette_three(t_data *data);
int			burningship(long double x, long double y);
void		draw_burningship(t_data *data, int destroy);
long double	ft_abs(long double x);
int			ft_strcmp(const char *s1, const char *s2);
void		hooks_function(t_data *data);
void		value_assignment(t_data *data);
void		fill_args_and_check_errors(int argc, char **argv, t_data *data);
void		burning_or_mandel_or_julia(int argc, t_data *data, int choice);
void		draw_sinusoidal_mandelbrot(t_data *data, int destroy);
void		switch_fractals(t_data *data);
void		draw_fractals(t_data *data);

#endif