/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:32:04 by del-yaag          #+#    #+#             */
/*   Updated: 2023/12/09 15:36:05 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	exit(0);
	return (0);
}

int	key_move(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		exit(0);
	}
	else if (keycode == 48)
	{
		data->set_color += 1;
		change_color(data);
	}
	else if (keycode == N_KEY)
	{
		if (data->power_n == -2)
			data->power_n = 2;
		data->power_n += 1;
		if (!ft_strcmp(data->type, "multi3"))
			draw_multibrot3(data, 1);
		else
			data->power_n = 2;
	}
	else if (keycode == B_KEY) {

		if (data->power_n > 2)
		{
			data->power_n -= 1;
			if (!ft_strcmp(data->type, "multi3"))
				draw_multibrot3(data, 1);
			else
				data->power_n = 2;
		}
		else if ( data->power_n == 2)
			data->power_n = -2;
		else if (data->power_n <= -2)
		{
			data->power_n -= 1;
			if (!ft_strcmp(data->type, "multi3"))
				draw_multibrot3(data, 1);
			else
				data->power_n = 2;
		}
		else 
			data->power_n = 2;
	}
	else if (keycode == I_KEY) {
		
		data->iteration_n += 1;
	}
	else if (keycode == 124)
		data->left_right += 20;
	else if (keycode == 123)
		data->left_right += -20;
	else if (keycode == 126)
		data->top_down += -20;
	else if (keycode == 125)
		data->top_down += 20;
	else if (keycode == 36)
		switch_fractals(data);
	else {
		printf("%d\n", keycode);
		return (0);
	}
	draw_fractals(data);
	return (0);
}

int	mouse_zoom(int mousecode, int x, int y, t_data *data)
{
	if (mousecode != 4 && mousecode != 5)
		return (0);
	if (mousecode == 4)
	{
		x = x - (WIDTH / 2);
		y = y - (WIDTH / 2);
		data->zoom *= ZOOM;
		data->left_right *= ZOOM;
		data->top_down *= ZOOM;
		data->left_right += x * (ZOOM - 1);
		data->top_down += y * (ZOOM - 1);
	}
	else if (mousecode == 5)
	{
		data->zoom /= ZOOM;
		data->left_right /= ZOOM;
		data->top_down /= ZOOM;
	}
	draw_fractals(data);
	return (0);
}
