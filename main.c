/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:38:38 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/23 16:24:50 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_cpl	newcpl(double a, double b)
{
	t_cpl	new_cpl;

	new_cpl.a = a;
	new_cpl.b = b;
	return (new_cpl);
}

void	init_fractal(t_cpl pmin, t_cpl pmax, t_env *ptr, int fractal)
{
	ptr->type.x_min = pmin.a;
	ptr->type.x_max = pmax.a;
	ptr->type.y_min = pmin.b;
	ptr->type.y_max = pmax.b;
	ptr->type.name = fractal;
	ptr->type.pause = 0;
	ptr->type.zoom = 0.2;
	ptr->type.cc = 1;
	ptr->type.puissance = 2;
}

void	read_arg(char *av, t_env *ptr)
{
	if ((ft_strcmp(av, "mandelbrot") == 0) || (ft_strcmp(av, "mandelbrot3") == 0))
	{
		ptr->win = mlx_new_window(ptr->mlx, ptr->width, ptr->height, av);
		init_fractal(newcpl(-2.1, -1.2), newcpl(0.6, 1.2), ptr, 1);
		if (ft_strcmp(av, "mandelbrot3") == 0)
			ptr->type.puissance = 3;
		mandelbrot(ptr);
		ft_event(ptr);
	}
	else if ((ft_strcmp(av, "julia") == 0) || (ft_strcmp(av, "julia3") == 0))
	{	
		ptr->win = mlx_new_window(ptr->mlx, ptr->width, ptr->height, av);
		init_fractal(newcpl(-2, -2), newcpl(2, 2), ptr, 2);
		if (ft_strcmp(av, "julia3") == 0)
			ptr->type.puissance = 3;
		julia(ptr, 0, 0);
		ft_event(ptr);
	}
	else if (ft_strcmp(av, "ship") == 0)
	{		
		ptr->win = mlx_new_window(ptr->mlx, ptr->width, ptr->height, av);
		init_fractal(newcpl(-2.5, -2.5), newcpl(2.5, 2.5), ptr, 3);
		ship(ptr);
		ft_event(ptr);
	}
	else
	{
		ft_putstr("caca\n");
		exit (0);
	}
}

int		main(int ac, char **av)
{
	int i;
	t_env	ptr;

	i = 1;
	ptr.mlx = mlx_init();
	ptr.width = 600;
	ptr.height = 600;
	ptr.type.nb_i = 30;
	ptr.cursor.x = 0;
	ptr.cursor.y = 0;
	while (ac > 1)
	{
		read_arg(av[i], &ptr);
		//ft_event(&ptr);
		i++;
		ac--;
	}
	mlx_loop(ptr.mlx);
	return (0);
}
