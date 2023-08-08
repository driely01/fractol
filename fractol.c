/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:19:02 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 16:48:41 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		fill_args_and_check_errors(argc, argv, &data);
		value_assignment(&data);
		data.type = argv[1];
		if (!ft_strcmp(argv[1], "Julia"))
			burning_or_mandel_or_julia(argc, &data, 3);
		else if (!ft_strcmp(argv[1], "Mandelbrot"))
			burning_or_mandel_or_julia(argc, &data, 1);
		else if (!ft_strcmp(argv[1], "Burningship"))
			burning_or_mandel_or_julia(argc, &data, 2);
		hooks_function(&data);
		mlx_loop(data.mlx);
	}
	else
		how_to_pass_param();
	return (0);
}
