/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:38:38 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/27 13:22:59 by marnaud          ###   ########.fr       */
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
	ptr->type.nb_i = 30;
	ptr->cursor.x = 0;
	ptr->cursor.y = 0;
	ptr->type.x_min = pmin.a;
	ptr->type.x_max = pmax.a;
	ptr->type.y_min = pmin.b;
	ptr->type.y_max = pmax.b;
	ptr->type.name = fractal;
	ptr->type.pause = 0;
	ptr->type.zoom = 0.2;
	ptr->type.cc = 1;
	ptr->type.puissance = 2;
	ptr->color.r = 236;
	ptr->color.g = 12;
	ptr->color.b = 117;
}

void	draw_first_img(t_env *ptr, int cas)
{
	if (cas < 3)
	{
		init_fractal(newcpl(-2.1, -1.2), newcpl(0.6, 1.2), ptr, 1);
		if (cas == 2)
			ptr->type.puissance = 3;
		mandelbrot(ptr);
	}
	else if (cas < 5)
	{
		init_fractal(newcpl(-2, -2), newcpl(2, 2), ptr, 2);
		if (cas == 4)
			ptr->type.puissance = 3;
		julia(ptr, 0, 0);
	}
	else
	{
		init_fractal(newcpl(-2.5, -2.5), newcpl(2.5, 2.5), ptr, 3);
		ship(ptr);
	}
}
