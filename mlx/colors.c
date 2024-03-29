/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:11:53 by del-yaag          #+#    #+#             */
/*   Updated: 2023/12/09 13:06:47 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	palette_one(t_data *data)
{
	if (data->c_itr < (data->iteration_n * 10 / 100))
		data->p_color = 0x29132e;
	else if (data->c_itr < (data->iteration_n * 40 / 100))
		data->p_color = 0xf887ff;
	else if (data->c_itr < (data->iteration_n * 60 / 100))
		data->p_color = 0xde004e;
	else if (data->c_itr < (data->iteration_n * 80 / 100))
		data->p_color = 0x860029;
	else
		data->p_color = 0x321450;
}

void	palette_two(t_data *data)
{
	if (data->c_itr < (data->iteration_n * 10 / 100))
		data->p_color = 0x222035;
	else if (data->c_itr < (data->iteration_n * 20 / 100))
		data->p_color = 0xdefe47;
	else if (data->c_itr < (data->iteration_n * 30 / 100))
		data->p_color = 0xff6e27;
	else if (data->c_itr < (data->iteration_n * 40 / 100))
		data->p_color = 0x120458;
	else if (data->c_itr < (data->iteration_n * 50 / 100))
		data->p_color = 0x393f5f;
	else if (data->c_itr < (data->iteration_n * 60 / 100))
		data->p_color = 0x351409;
	else if (data->c_itr < (data->iteration_n * 70 / 100))
		data->p_color = 0xfe00fe;
	else if (data->c_itr < (data->iteration_n * 80 / 100))
		data->p_color = 0x00b3fe;
	else if (data->c_itr < (data->iteration_n * 90 / 100))
		data->p_color = 0xe2dddf;
	else
		data->p_color = 0x0013ee;
}

void	palette_org(t_data *data)
{
	data->p_color = (255 - (data->c_itr / data->iteration_n) * 255);
}

void	palette_cos(t_data *data)
{
	data->p_color = (255 - (data->c_itr / data->iteration_n) * 255)
		/ (cos(data->c_itr / data->iteration_n)
			* sin(data->c_itr / data->iteration_n)
			* tan(data->c_itr / data->iteration_n));
}

void	palette_three(t_data *data)
{
	if (data->c_itr < (data->iteration_n * 10 / 100))
		data->p_color = 0x222035 * ((data->c_itr / data->iteration_n) * 255);
	else if (data->c_itr < (data->iteration_n * 20 / 100))
		data->p_color = 0xdefe47 / ((data->c_itr / data->iteration_n) * 255);
	else if (data->c_itr < (data->iteration_n * 30 / 100))
		data->p_color = 0xff6e27 * ((data->c_itr / data->iteration_n) * 255);
	else if (data->c_itr < (data->iteration_n * 40 / 100))
		data->p_color = 0x120458 / ((data->c_itr / data->iteration_n) * 255);
	else if (data->c_itr < (data->iteration_n * 50 / 100))
		data->p_color = 0x393f5f * ((data->c_itr / data->iteration_n) * 255);
	else if (data->c_itr < (data->iteration_n * 60 / 100))
		data->p_color = 0x351409 / ((data->c_itr / data->iteration_n) * 255);
	else if (data->c_itr < (data->iteration_n * 70 / 100))
		data->p_color = 0xfe00fe * ((data->c_itr / data->iteration_n) * 255);
	else if (data->c_itr < (data->iteration_n * 80 / 100))
		data->p_color = 0x00b3fe / ((data->c_itr / data->iteration_n) * 255);
	else if (data->c_itr < (data->iteration_n * 90 / 100))
		data->p_color = 0xe2dddf * ((data->c_itr / data->iteration_n) * 255);
	else
		data->p_color = 0x0013ee / ((data->c_itr / data->iteration_n) * 255);
}
