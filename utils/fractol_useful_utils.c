/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_useful_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:24:14 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 16:37:12 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

void	hooks_function(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, destroy, data);
	mlx_mouse_hook(data->mlx_win, mouse_zoom, data);
	mlx_hook(data->mlx_win, 2, 0, key_move, data);
}

void	value_assignment(t_data *data)
{
	data->zoom = WIDTH / 4;
	data->left_right = 0;
	data->top_down = 0;
	data->set_color = 1;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
}

void	fill_args_and_check_errors(int argc, char **argv, t_data *data)
{
	if (ft_strcmp(argv[1], "Julia") && ft_strcmp(argv[1], "Mandelbrot")
		&& ft_strcmp(argv[1], "Burningship"))
		how_to_pass_param();
	if (argc == 4)
	{
		data->f_const = ft_atof(argv[2]);
		data->s_const = ft_atof(argv[3]);
	}
}

void	burning_or_mandel_or_julia(int argc, t_data *data, int choice)
{
	if (choice == 1)
	{
		if (argc == 2)
			draw_mandlbrotset(data, 0);
		else
			how_to_pass_param();
	}
	else if (choice == 2)
	{
		if (argc == 2)
			draw_burningship(data, 0);
		else
			how_to_pass_param();
	}
	else if (choice == 3)
	{
		if (argc <= 4)
			draw_juliaset(data, 0, data->f_const, data->s_const);
		else
			how_to_pass_param();
	}
}
