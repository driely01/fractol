/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:52:27 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 16:37:12 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	how_to_pass_param(void)
{
	ft_putstr_fd("####################################\
###########################################\n", 1);
	ft_putstr_fd("#                                      \
                                       #\n", 1);
	ft_putstr_fd("# >   Invalid Parameter Try Again     \
                                        #\n", 1);
	ft_putstr_fd("#                                      \
                                       #\n", 1);
	ft_putstr_fd("# >   If you need to execute a Mandelnro\
tset fractal you execute af follow:   #\n", 1);
	ft_putstr_fd("#                                       \
                                      #\n", 1);
	ft_putstr_fd("# >   ./exec <Mandelbrot>                \
                                     #\n", 1);
	ft_putstr_fd("#                                       \
                                      #\n", 1);
	ft_putstr_fd("# >   If you need to execute a Julia frac\
tal you execute af follow:           #\n", 1);
	ft_putstr_fd("#                                        \
                                     #\n", 1);
	ft_putstr_fd("# >   ./exec <Julia> <first const> <second\
 const>                             #\n", 1);
	ft_putstr_fd("#                                         \
                                    #\n", 1);
	ft_putstr_fd("# >   for examles:                        \
                                    #\n", 1);
	ft_putstr_fd("#                                         \
                                    #\n", 1);
	ft_putstr_fd("# >   ./exec Julia -0.72689 0.1889        \
                                    #\n", 1);
	ft_putstr_fd("#                                         \
                                    #\n", 1);
	ft_putstr_fd("##########################################\
#####################################\n", 1);
	exit(1);
}

static double	ft_convert(const char **str, int *sign,
				double *res, double *old)
{
	*old = *res;
	*res *= 10;
	if ((*res / 10) != *old && *sign == 1)
		return (-1);
	if ((*res / 10) != *old && *sign == -1)
		return (0);
	return (*res += (*(*str) - 48));
}

static double	ft_calculater(const char **str, int sign)
{
	double	res;
	double	old;
	int		counter;

	res = 0;
	counter = 1;
	while (*(*str) >= '0' && *(*str) <= '9')
	{
		ft_convert(str, &sign, &res, &old);
		(*str)++;
	}
	if (*(*str) == '.')
	{
		(*str)++;
		if (*(*str) < '0' || *(*str) > '9')
			how_to_pass_param();
		while (*(*str) >= '0' && *(*str) <= '9')
		{
			ft_convert(str, &sign, &res, &old);
			counter *= 10;
			(*str)++;
		}
	}
	return ((res * sign) / counter);
}

double	ft_atof(const char *str)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '+'
			&& str[i] != '-')
			how_to_pass_param();
		i++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (ft_calculater(&str, sign));
}
