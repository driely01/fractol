/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:19:02 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/08 22:34:38 by del-yaag         ###   ########.fr       */
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

int destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	exit(0);
	return (0);
}

long double ft_abs(long double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	juliaset(long double x, long double y, long double comp_one, long double comp_two)
{
	int		n;
	long double tmp;
	long double	a;
	long double	b;
	
	n = 0;
	a = x;
	b = y;
	while (n < num_itr) {
		tmp = a;
		a = a * a - b * b + comp_one;
		b = 2 * tmp * b + comp_two;
		
		if (sqrt(a*a + b*b) > 2.0)
			break ;
		n++;
	}
	return (n);
}

int	mandlbrotset(long double x, long double y)
{
	int n = 0;
  long double a = x;
  long double b = y;
  while (n < num_itr) {
    long double tmp = a;
    a = a * a - b * b + x;
    b = 2 * tmp * b + y;
    if (sqrt(a * a + b * b) > 2.0)
      break;
    n++;
  }
  return n;
}
// int	mandlbrotset(long double x, long double y)
// {
// 	int		n;
// 	long double tmp;
// 	long double	a;
// 	long double	b;
	
// 	n = 0;
// 	a = 0;
// 	b = 0;
// 	while (n < num_itr) {
// 		tmp = a;
// 		a = a * a - b * b + x;
// 		b = 2 * tmp * b + y;
// 		if (sqrt(a*a + b*b) > 2.0)
// 			break ;
// 		n++;
// 	}
// 	return (n);
// }

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_mandlbrotset(t_data *data, int destroy)
{
	long double	x;
	long double	y;
	// char	*color;
	int 	p_color;
	int		n;
	
	if (destroy == 1)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1200, 1200);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	x = 0;
	while (x < width) {
		y = 0;
		while (y < height) {
			n = mandlbrotset((x - width / 2 + data->left_right)/data->zoom, (y - height / 2 + data->top_down)/data->zoom);
			p_color = (n / num_itr) * 255;
			// color = data->addr + ((int)x  * (data->bits_per_pixel / 8) + (int)(y)  * data->line_length);
			// if (n < num_itr)
			// 	*(int *)color=  create_trgb(0, p_color * n, p_color * n, p_color * n);
			// else
			// 	*(int *)color=  create_trgb(0, p_color / n, p_color / n, p_color / n);
			if (n < num_itr)
				my_mlx_pixel_put(data, x, y, p_color);
			else
				my_mlx_pixel_put(data, x, y, p_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	draw_juliaset(t_data *data, int destroy, long double comp_one, long double comp_two)
{
	long double	x;
	long double	y;
	// char	*color;
	int 	p_color;
	int		n;
	
	if (destroy == 1)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1200, 1200);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	x = 0;
	while (x < width) {
		y = 0;
		while (y < height) {
			n = juliaset((x - width / 2 + data->left_right)/data->zoom,
				(y - height / 2 + data->top_down)/data->zoom, comp_one, comp_two);
			p_color = (n / num_itr) * 255;
			// color = data->addr + ((int)x  * (data->bits_per_pixel / 8) + (int)(y)  * data->line_length);
			// if (n < num_itr)
			// 	*(int *)color=  create_trgb(0, p_color, p_color, p_color);
			// else
				// *(int *)color=  create_trgb(0, p_color, p_color, p_color);
			if (n <= num_itr)
				my_mlx_pixel_put(data, x, y, p_color *  num_itr);
			else
				my_mlx_pixel_put(data, x, y, p_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int mouse_zoom(int mousecode, int x, int y, t_data *data)
{

	if (mousecode != 4 && mousecode != 5)
		return (0);
	if (mousecode == 4)
	{
		x = x - (width / 2);
		y = y - (width / 2);
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
	if (!ft_strcmp(data->type, "Mandlbrot"))
		draw_mandlbrotset(data, 1);
	else if (!ft_strcmp(data->type, "Julia"))
		draw_juliaset(data, 1, data->f_const, data->s_const);
	return (0);
}

int key_move(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		exit(0);
	}
	if (keycode == 124)
		data->left_right += 20;
	else if (keycode == 123)
		data->left_right += -20;
	else if (keycode == 126)
		data->top_down += -20;
	else if (keycode == 125)
		data->top_down += 20;
	else
		return (0);
	if (!ft_strcmp(data->type, "Mandlbrot"))
		draw_mandlbrotset(data, 1);
	else if (!ft_strcmp(data->type, "Julia"))
		draw_juliaset(data, 1, data->f_const, data->s_const);
	return (0);
}

void hooks_function(t_data *data)
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
		data.zoom = width / 4;
		data.left_right = data.top_down = 0;
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, width, height, "Fractol");
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
