/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliaset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:16:11 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/10 16:44:04 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_juliaset(t_data *data, int destroy,
				long double comp_one, long double comp_two)
{
	long double	x;
	long double	y;
	char		*color;
	int			p_color;
	int			n;

	if (destroy == 1)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1200, 1200);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			n = juliaset((x - WIDTH / 2 + data->left_right) / data->zoom, (y
						- HEIGHT / 2 + data->top_down)
					/ data->zoom, comp_one, comp_two);
			p_color = 255 - (n / NUM_ITR) * 255;
			color = data->addr + ((int)x * (data->bits_per_pixel / 8)
					+ (int)y * data->line_length);
			if (n < NUM_ITR)
				*(int *)color = create_trgb(0, p_color, p_color, p_color);
			else
				*(int *)color = create_trgb(0, p_color, p_color, p_color);
			y++;
		}
        x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	juliaset(long double x, long double y,
		long double comp_one, long double comp_two)
{
	int			n;
	long double	tmp;
	long double	a;
	long double	b;

	n = 0;
	a = x;
	b = y;
	while (n < NUM_ITR)
	{
		tmp = a;
		a = a * a - b * b + comp_one;
		b = 2 * tmp * b + comp_two;
		if (sqrt(a * a + b * b) > 2.0)
			break ;
		n++;
	}
	return (n);
}
