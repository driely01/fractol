/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:11:41 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/08 22:33:25 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <libc.h>
#include <mlx.h>
#include <math.h>

#define width 800
#define height 800
#define num_itr 100.0
#define ZOOM 1.1

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

double	ft_atof(const char *str);
void	how_to_pass_param();

#endif