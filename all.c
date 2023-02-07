/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:58:19 by del-yaag          #+#    #+#             */
/*   Updated: 2023/02/06 11:59:00 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libc.h>
#include <math.h>

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		j;
	int		xp;
	int		yp;

	xp = x;
	yp = y;
	while (x < xp + 100)
	{
		j = y;
		while (j < yp + 100)
		{
			dst = data->addr + (j * data->line_length + x
					* (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			j++;
		}
		x++;
	}
}

int	func(int param)
{
	if (param == 53)
		exit (0);
	return (0);
}

int destroy(void *param)
{
	exit(0);
	return (0);
}

// int	main(void)
// {
// 	t_data	data;
// 	int		x;
// 	int		y;
// 	int		a;
// 	int		b;

// 	a = 600;
// 	b = 600;
// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, 1200, 1200, "CIRCLE");
// 	data.img = mlx_new_image(data.mlx, 1200, 1200);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
// 			&data.line_length, &data.endian);
// 	my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
// 	my_mlx_pixel_put(&data, 1200 - 105, 5, 0x00FF0000);
// 	my_mlx_pixel_put(&data, 5, 1200 - 105, 0x00FF0000);
// 	my_mlx_pixel_put(&data, 1200 - 105, 1200 - 105, 0x00FF0000);
// 	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
// 	x = 0;
// 	while (x < 1200)
// 	{
// 		y = 0;
// 		while (y < 1200)
// 		{
// 			if (sqrt(pow(y - a, 2) + pow(x - b, 2)) == 300)
// 				mlx_pixel_put(data.mlx, data.mlx_win, y, x, 0x00FF0000);
// 			// else
// 			// 	mlx_pixel_put(data.mlx, data.mlx_win, x, y, 0x00FF0000);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_hook(data.mlx_win, 17, 0, func, &data);
// 	mlx_loop(data.mlx);
// }

// int	here(int x)
// {
// 	return (-x);
// }

// int line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
// {
// 	double deltaX = endX - beginX; // 10
// 	double deltaY = endY - beginY; // 0

// 	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// //  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
// 	deltaX /= pixels; // 1
// 	deltaY /= pixels; // 0
// 	double pixelX = beginX;
// 	double pixelY = beginY;
// 	while (pixels)
// 	{
// 		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// 		pixelX += deltaX;
// 		pixelY += deltaY;
// 		--pixels;
// 	}
// 	return 0;
// }

// void pos(int *posx, int *color, int j)
// {
// 	if (j == 2)
// 	{
// 		*posx += *posx / 2;
// 		*color = 0x00FFF40F;
// 	}
// 	else if (j == 3)
// 	{
// 		*posx += *posx;
// 		*color = 0x003BFF0F;
// 	}
// 	else if (j == 4)
// 	{
// 		*posx -= *posx/2;
// 		*color = 0x000FFFFD;
// 	}
// 	else if (j == 5)
// 	{
// 		*posx -= *posx;
// 		*color = 0x000F29FF;	
// 	}
// }

// void draw_circles(t_data data, int pxxx, double x, double y, double *ang, double *defAng, int posx, int posy)
// {
// 	int		i;
// 	int		j;
// 	int		isf;
// 	int		px;
// 	int		pxx;
// 	int		pyy;
// 	int		color;
// 	double 	preX = 0;
// 	double	preY = 0;

// 	isf = 1;
// 	j = 1;
// 	color = 0x00FF0000;
// 	while (j <= 5)
// 	{	
// 		i = 1;
// 		px = pxxx;
// 		pxx = posx;
// 		pyy = posy;
// 		pos(&pxx, &color, j);
// 		while (i <= 40)
// 		{	
// 			while (*ang <= 2 * M_PI)
// 			{
// 				x = px * cos(*ang) + pxx;
// 				y = px * sin(*ang) + pyy;
// 				if(isf)
// 				{
// 					preX = x;
// 					preY = y;
// 					isf = 0;
// 				}
// 				line(data.mlx, data.mlx_win, preX, preY, x, y, color);
// 				preX = x;
// 				preY = y;
// 				*ang += *defAng;
// 			}
// 			px = px/1.2;
// 			*ang = 0;
// 			i++;
// 		}
// 		j++;
// 	}
// }

double ft_abs(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	iteration(double x, double y)
{
	int		n;
	// double	aa;
	// double	bb;
	double tmp;
	double	a;
	double	b;
	
	n = 0;
	a = 0;
	b = 0;
	while (n < 50) {
		tmp = a;
		a = a * a - b * b + x;
		b = 2 * tmp * b + y;
		
		if (sqrt(a*a + b*b) > 2.0)
			break ;
		n++;
	}
	return (n);
}
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int main(void)
{
	int		iter;
	int		n;
	t_data	data;
	double	x;
	double	y;
	double	height;
	double	width;
	char	*color;
	int 	p_color;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1200, 1200, "CIRCLE");
	data.img = mlx_new_image(data.mlx, 1200, 1200);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	height = 1200;
	width = 1200;
	x = 0;
	while (x < width) {
		y = 0;
		while (y < height) {
			n = iteration((x - 600)/300.0, (y - 600)/300.0);
			p_color = 255 - (n / 50.0) * 254;
			color = data.addr + ((int)x  * (data.bits_per_pixel / 8) + (int)(y)  * data.line_length);
			*(int *)color=  create_trgb(0, p_color, p_color, p_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 2, 0, func, &data);
	mlx_mouse_hook(data.mlx_win, mouse_hook, &data);
	mlx_loop(data.mlx);
}

// int	main(void)
// {
// 	t_data	data;
// 	double	x;
// 	double	y;
// 	double	ang = 0;
// 	double	defAng = 0.001;
// 	double	px;
// 	int		i;
// 	int		posx;
// 	int		posy;
// 	double	scale;
// 	double 	preX = 0;
// 	double	preY = 0;
// 	int		isf;
// 	char	*color;
// 	int		xx;
// 	int		yy;

// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, 1200, 1200, "CIRCLE");
// 	data.img = mlx_new_image(data.mlx, 1200, 1200);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
// 			&data.line_length, &data.endian);

// 	posx = 600;
// 	posy = 0;
// 	scale = 300;
// 	i = 1;
// 	isf = 1;
	
// 	while (ang <= 2 * M_PI)
// 	{
// 		x = px * cos(ang) + 600;
// 		y = px * sin(ang) + 600;
// 		draw_circles(data, scale, x, y, &ang, &defAng, posx, posy);
// 		scale = scale + 150;
// 		posy = posy + 150;
// 		ang += defAng;
// 	}

// 	draw_circles(data, scale, x, y, &ang, &defAng, posx, posy);
// 	while (i <= 25)
// 	{		
// 		draw_circles(data, scale, x, y, &ang, &defAng, posx, posy);
// 		scale = scale - 70;
// 		posy = posy + 60;
// 		i++;
// 	}
// 	mlx_hook(data.mlx_win, 2, 0, func, &data);
// 	mlx_hook(data.mlx_win, 17, 0, destroy, &data);
// 	mlx_loop(data.mlx);
// }

// int	main(void)
// {
// 	t_data	data;
// 	double		x;
// 	double		y;
// 	double 	preX = 0;
// 	double	preY = 0;
// 	int		a;
// 	int		b;
// 	//char	*color;

// 	int isf;

// 	isf = 1;
// 	a = 600;
// 	b = 600;
// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, 1200, 1200, "CIRCLE");
// 	data.img = mlx_new_image(data.mlx, 1200, 1200);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
// 			&data.line_length, &data.endian);

	
// 	// y = 0;
// 	// while (y < 1200)
// 	// {
// 	// 	x = 0;
// 	// 	while (x < 1200)
// 	// 	{
// 			// if (sqrt(pow(x - a, 2) + pow(y - b, 2)) == 300)
// 			// {
// 				// color = data.addr + (x * (data.bits_per_pixel / 8) + y  * data.line_length);
// 				// *(int *)color= 0xFF0000;
				
// 				// line(data.mlx, data.mlx_win, preX, preY, x, y, 0x00FFFFFF);
// 				// preX = x;
// 				// preY = y;
// 	// 		}
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// 	double ang = 0;
// 	double defAng = 0.001;
// 	while (ang <= 2*M_PI)
// 	{
// 		x = 300*cos(ang) + 600;
// 		y = 300*sin(ang) + 600;
// 		if(isf)
// 		{
// 			preX = x;
// 			preY = y;
// 			isf = 0;
// 		}
// 		line(data.mlx, data.mlx_win, preX, preY, x, y, 0x00FFFFFF);

// 		preX = x;
// 		preY = y;
// 		ang += defAng;
// 	}
// 	//mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
// 	mlx_hook(data.mlx_win, 2, 0, func, &data);
// 	//draw_line(data.mlx, data.mlx_win, 0,600,1200,600,0x00FFFFFF);
// 	mlx_loop(data.mlx);
// }

// int	here(int x)
// {
// 	return (-x);
// }
// int	main(void)
// {
// 	t_data	data;
// 	int		x;
// 	int		y;
// 	int		a;
// 	int		b;
// 	char	*color;

// 	a = 600;
// 	b = 600;
// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, 1200, 1200, "CIRCLE");
// 	data.img = mlx_new_image(data.mlx, 1200, 1200);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
// 			&data.line_length, &data.endian);

	
// 	x = 0;
// 	while (x < 1200)
// 	{
// 		y = x - 600;
// 		if (y <= 600 && y >= -600)
// 		{
// 			printf("xp===>%d y==>%d\n", (x + 600), y);
			
// 			color = data.addr + (x * (data.bits_per_pixel / 8) + y  * data.line_length);
// 			*(int *)color= 0xFF0000;
// 		}
// 		printf("x ==> %d\n", x);
// 		x++;
// 	}
// 	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
// 	mlx_hook(data.mlx_win, 2, 0, func, &data);
// 	mlx_loop(data.mlx);
// }