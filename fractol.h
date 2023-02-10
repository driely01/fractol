/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:11:41 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/10 16:50:01 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libc.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define NUM_ITR 80.0
# define ZOOM 1.1

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	char	*type;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	left_right;
	double	top_down;
	double	f_const;
	double	s_const;
}	t_data;

int		create_trgb(int t, int r, int g, int b);
double	ft_atof(const char *str);
void	how_to_pass_param(void);
int		juliaset(long double x, long double y,
			long double comp_one, long double comp_two);
void	draw_juliaset(t_data *data, int destroy,
			long double comp_one, long double comp_two);
void	draw_mandlbrotset(t_data *data, int destroy);
int		mandlbrotset(long double x, long double y);
int		destroy(t_data *data);
int		key_move(int keycode, t_data *data);
int		mouse_zoom(int mousecode, int x, int y, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
#endif