/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multimandlbrot3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:19:58 by del-yaag          #+#    #+#             */
/*   Updated: 2023/12/09 11:26:07 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	multibrot3(t_data *data, long double x, long double y)
{
	int			n;
	long double	a;
	long double	b;
	long double	tmp;

	n = 0;
	a = x;
	b = y;
	while (n < data->iteration_n)
	{
		tmp = a;
		a = pow((pow(a, 2) + pow(b, 2)), (data->power_n / 2)) * cos(data->power_n * atan2(b, a)) + x;
		b = pow((pow(tmp, 2) + pow(b, 2)), (data->power_n / 2)) * sin(data->power_n * atan2(b, tmp)) + y;
		if (sqrt(a * a + b * b) > 20.0)
			break ;
		n++;
	}
	return (n);
}

void	draw_multibrot3(t_data *data, int destroy)
{
	long double	x;
	long double	y;

	if (destroy == 1)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
	}
	data->img = mlx_new_image(data->mlx, 1200, 1200);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			data->c_itr = multibrot3(data, (x - WIDTH / 2 + data->left_right)
					/ data->zoom, (y - HEIGHT / 2 + data->top_down)
					/ data->zoom);
			data->color = data->addr + ((int)x * (data->bits_per_pixel / 8)
					+ (int)y * data->line_length);
			change_color(data);
			*(int *)data->color = data->p_color;
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
