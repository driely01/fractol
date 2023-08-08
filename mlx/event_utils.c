/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:48:16 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 16:37:12 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

void	draw_fractals(t_data *data)
{
	if (!ft_strcmp(data->type, "Mandelbrot"))
		draw_mandlbrotset(data, 1);
	else if (!ft_strcmp(data->type, "Julia"))
		draw_juliaset(data, 1, data->f_const, data->s_const);
	else if (!ft_strcmp(data->type, "Burningship"))
		draw_burningship(data, 1);
	else if (!ft_strcmp(data->type, "Sinusoidalmandelbrot"))
		draw_sinusoidal_mandelbrot(data, 1);
}

void	switch_fractals(t_data *data)
{
	data->left_right = 0;
	data->top_down = 0;
	if (!ft_strcmp(data->type, "Burningship"))
	{
		data->type = "Sinusoidalmandelbrot";
		data->zoom = WIDTH / 16;
        data->left_right = 0;
	}
	else if (!ft_strcmp(data->type, "Sinusoidalmandelbrot"))
	{
		data->type = "Burningship";
		data->zoom = WIDTH / 4;
	}
}
