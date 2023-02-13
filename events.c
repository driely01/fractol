/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:32:04 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/13 18:08:05 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	exit(0);
	return (0);
}

void	change_color(t_data *data)
{
	if (data->set_color == 5)
		data->set_color = 1;
	if (data->set_color == 1)
		palette_org(data);
	else if (data->set_color == 2)
		palette_one(data);
	else if (data->set_color == 3)
		palette_two(data);
	else if (data->set_color == 4)
		palette_three(data);
}

static void	draw_fractals(t_data *data)
{
	if (!ft_strcmp(data->type, "Mandelbrot"))
		draw_mandlbrotset(data, 1);
	else if (!ft_strcmp(data->type, "Julia"))
		draw_juliaset(data, 1, data->f_const, data->s_const);
	else if (!ft_strcmp(data->type, "Burningship"))
		draw_burningship(data, 1);
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
	else if (keycode == 124)
		data->left_right += 20;
	else if (keycode == 123)
		data->left_right += -20;
	else if (keycode == 126)
		data->top_down += -20;
	else if (keycode == 125)
		data->top_down += 20;
	else
		return (0);
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
	if (!ft_strcmp(data->type, "Mandelbrot"))
		draw_mandlbrotset(data, 1);
	else if (!ft_strcmp(data->type, "Julia"))
		draw_juliaset(data, 1, data->f_const, data->s_const);
	else if (!ft_strcmp(data->type, "Burningship"))
		draw_burningship(data, 1);
	return (0);
}
