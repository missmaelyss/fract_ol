/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:38:38 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/22 16:28:26 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
int		ft_esc(int k, t_env	*ptr)
{
	if (k == 35)
	{
		ptr->type.pause = (ptr->type.pause + 1) % 2;
//		mlx_do_key_autorepeatoff(ptr->mlx);
	}
	if (k == 78)
	{
		ptr->type.nb_i--;
		if (ptr->type.name == 1)
			mandelbrot(ptr);
		if (ptr->type.name == 2)
			julia(ptr, ptr->cursor.x, ptr->cursor.y);
	}
	if (k == 69)
	{
		ptr->type.nb_i++;
		if (ptr->type.name == 1)
			mandelbrot(ptr);
		if (ptr->type.name == 2)
			julia(ptr, ptr->cursor.x, ptr->cursor.y);
	}
	if (k == 53)
		exit(0);
	return (1);
}

int		ft_event(t_env *ptr)
{
	mlx_key_hook(ptr->win, ft_esc, ptr);
	
	mlx_mouse_hook(ptr->win, ft_zoom, ptr);
	if (ptr->type.name == 2)
	{
		mlx_do_key_autorepeaton(ptr->mlx);
		mlx_hook(ptr->win, 6, (1L<<6), ft_follow_mouse, ptr);
	}
	return (1);
}

t_cpl	newCpl(double a, double b)
{
	t_cpl	new_cpl;

	new_cpl.a = a;
	new_cpl.b = b;
	return (new_cpl);
}


void init_fractal(t_cpl pmin, t_cpl pmax, t_env *ptr, int fractal)
{
	ptr->type.x_min = pmin.a;
	ptr->type.x_max = pmax.a;
	ptr->type.y_min = pmin.b;
	ptr->type.y_max = pmax.b;
	ptr->type.name = fractal;
	ptr->type.pause = 0;
	ptr->type.PuissanceZoom = 0.2;
}

int 	main(int ac, char **av)
{
	t_env	ptr;

	ptr.mlx = mlx_init();
	ptr.width = 600;
	ptr.height = 600;
	ptr.win = mlx_new_window(ptr.mlx, ptr.width, ptr.height, "test");
	ptr.type.nb_i = 30;
	ptr.cursor.x = 0;
	ptr.cursor.y = 0;
	if (ac != 2)
		return (printf("error\n"));
	if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		init_fractal(newCpl(-2.1, -1.2), newCpl(0.6, 1.2), &ptr, 1);
/*		ptr.type.x_min = -2.1;
		ptr.type.x_max = 0.6;
		ptr.type.y_min = -1.2;
		ptr.type.y_max = 1.2;
		ptr.type.name = 1;*/
		mandelbrot(&ptr);
	}
	if (ft_strcmp(av[1], "julia") == 0)
	{
		init_fractal(newCpl(-2, -2), newCpl(2, 2), &ptr, 2);
/*		ptr.type.x_min = -2;
		ptr.type.x_max = 2;
		ptr.type.y_min = -2;
		ptr.type.y_max = 2;
		ptr.type.name = 2;*/
		julia(&ptr, 0, 0);
	}
	ft_event(&ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
