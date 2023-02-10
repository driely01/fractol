/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:19:02 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/10 16:48:19 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] > str2[i] || str1[i] < str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (x * (data->bits_per_pixel / 8) + y * data->line_length);
	*(unsigned int *)dst = color;
}

long double	ft_abs(long double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	hooks_function(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, destroy, data);
	mlx_mouse_hook(data->mlx_win, mouse_zoom, data);
	mlx_key_hook(data->mlx_win, key_move, data);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{	
		if (ft_strcmp(argv[1], "Julia") && ft_strcmp(argv[1], "Mandlbrot"))
			how_to_pass_param();
		if (argc == 4)
		{
			data.f_const = ft_atof(argv[2]);
			data.s_const = ft_atof(argv[3]);
		}
		data.zoom = WIDTH / 4;
		data.left_right = 0;
		data.top_down = 0;
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
		if (!ft_strcmp(argv[1], "Julia"))
		{
			if (argc <= 4)
			{
				data.type = argv[1];
				draw_juliaset(&data, 0, data.f_const, data.s_const);
			}
			else 
				how_to_pass_param();
		}
		else if (!ft_strcmp(argv[1], "Mandlbrot"))
		{
			if (argc == 2)
			{	
				data.type = argv[1];
				draw_mandlbrotset(&data, 0);
			}
			else 
				how_to_pass_param();
		}
		hooks_function(&data);
		mlx_loop(data.mlx);
	}
	return (0);
}
