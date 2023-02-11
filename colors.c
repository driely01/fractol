/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:11:53 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/11 23:19:40 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	palette_one(t_data *data)
{
	if (data->c_itr < (NUM_ITR * 10 / 100))
		data->p_color = 0x29132e;
	else if (data->c_itr < (NUM_ITR * 40 / 100))
		data->p_color = 0xf887ff;
	else if (data->c_itr < (NUM_ITR * 60 / 100))
		data->p_color = 0xde004e;
	else if (data->c_itr < (NUM_ITR * 80 / 100))
		data->p_color = 0x860029;
	else
		data->p_color = 0x321450;
}

void	palette_two(t_data *data)
{
	if (data->c_itr < (NUM_ITR * 10 / 100))
		data->p_color = 0x222035;
	else if (data->c_itr < (NUM_ITR * 20 / 100))
		data->p_color = 0xdefe47;
	else if (data->c_itr < (NUM_ITR * 30 / 100))
		data->p_color = 0xff6e27;
	else if (data->c_itr < (NUM_ITR * 40 / 100))
		data->p_color = 0x120458;
	else if (data->c_itr < (NUM_ITR * 50 / 100))
		data->p_color = 0x393f5f;
	else if (data->c_itr < (NUM_ITR * 60 / 100))
		data->p_color = 0x351409;
	else if (data->c_itr < (NUM_ITR * 70 / 100))
		data->p_color = 0xfe00fe;
	else if (data->c_itr < (NUM_ITR * 80 / 100))
		data->p_color = 0x00b3fe;
	else if (data->c_itr < (NUM_ITR * 90 / 100))
		data->p_color = 0xe2dddf;
	else
		data->p_color = 0x0013ee;
}

void	palette_org(t_data *data)
{
	data->p_color = 255 - (data->c_itr / NUM_ITR) * 255;
}
