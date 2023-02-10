/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlbrotset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:19:58 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/10 17:18:55 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	mandlbrotset(long double x, long double y)
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
		a = a * a - b * b + x;
		b = 2 * tmp * b + y;
		if (sqrt(a * a + b * b) > 2.0)
			break ;
		n++;
	}
	return (n);
}

void	draw_mandlbrotset(t_data *data, int destroy)
{
	long double	x;
	long double	y;
	char		*color;
	double		p_color;
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
			n = mandlbrotset((x - WIDTH / 2 + data->left_right) / data->zoom,
					(y - HEIGHT / 2 + data->top_down) / data->zoom);
			p_color = (n / NUM_ITR) * 255;
			color = data->addr + ((int)x * (data->bits_per_pixel / 8)
					+ (int)y * data->line_length);
			*(int *)color = create_trgb(0, p_color, p_color, p_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
