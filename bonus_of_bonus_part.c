/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_of_bonus_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:49:55 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/15 18:41:21 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//  Z(n + 1) = Zn * sin(Zn)
static int	sinusoidal_mandelbrot(long double x, long double y)
{
	int			n;
	long double	a;
	long double	b;
	long double	tmp;

	n = 0;
	a = x;
	b = y;
	while (n < NUM_ITR)
	{
		tmp = a;
		a = ((tmp) * sin(tmp) * cosh(b) - (b) * cos(tmp) * sinh(b)) + x;
		b = ((tmp) * cos(tmp) * sinh(b) + (b) * sin(tmp) * cosh(b)) + y;
		if (sqrt(a * a + b * b) > 20.0)
			break ;
		n++;
	}
	return (n);
}

void	draw_sinusoidal_mandelbrot(t_data *data, int destroy)
{
	long double	x;
	long double	y;

	if (destroy == 1)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1200, 1200);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			data->c_itr = sinusoidal_mandelbrot((x - WIDTH / 2
						+ data->left_right) / data->zoom,
					(y - HEIGHT / 2 + data->top_down)
					/ data->zoom);
			data->color = data->addr + ((int)x * (data->bits_per_pixel / 8)
					+ (int)y * data->line_length);
			change_color(data);
			*(int *)data->color = data->p_color;
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
