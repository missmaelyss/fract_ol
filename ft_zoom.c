/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 12:09:17 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/22 16:47:16 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	move_interval(t_env *ptr, int x, int y, t_cpl sto)
{
	ptr->type.x_min -= ((ptr->width / 2) - x) * sto.a * ptr->type.PuissanceZoom;// 0.5;
	ptr->type.x_max -= ((ptr->width / 2) - x) * sto.a * ptr->type.PuissanceZoom;//0.5;
	ptr->type.y_min -= ((ptr->height / 2) - y) * sto.b * ptr->type.PuissanceZoom;//0.5;
	ptr->type.y_max -= ((ptr->height / 2) - y) * sto.b * ptr->type.PuissanceZoom;//0.5;
}

void	increase_or_decrease_it(int i, t_env *ptr, t_cpl sto)
{
	if (i == 1)
	{
		ptr->type.x_min += 0.01 * ptr->width * sto.a;
		ptr->type.x_max -= 0.01 * ptr->width * sto.a;
		ptr->type.y_min += 0.01 * ptr->height * sto.b;
		ptr->type.y_max -= 0.01 * ptr->height * sto.b;
	}
	if (i == 2)
	{
		ptr->type.x_min -= 0.01 * ptr->width * sto.a;
		ptr->type.x_max += 0.01 * ptr->width * sto.a;
		ptr->type.y_min -= 0.01 * ptr->height * sto.b;
		ptr->type.y_max += 0.01 * ptr->height * sto.b;
	}
}

 static void	ft_clear(t_env *ptr)
{
		mlx_clear_window(ptr->mlx, ptr->win);
		mlx_destroy_image(ptr->mlx, ptr->img);
}

/*
**		ptr->type.name == 1 signifie qu'on travail Mandelbrot 
**		ptr->type.name == 2 signifie qu'on travail Julia
*/

int		ft_zoom(int k, int x, int y, t_env *ptr)
{
	t_cpl	sto;

	sto.a = (ptr->type.x_max - ptr->type.x_min) / ptr->width;
	sto.b = (ptr->type.y_max - ptr->type.y_min) / ptr->height;
	if (k == 5 || k == 6 || (k == 1 && ptr->type.name == 2))
	{
		ft_clear(ptr);
		if (ptr->type.name == 1 || (k == 1 && ptr->type.name == 2 && ptr->type.pause == 0))
			move_interval(ptr, x, y, sto);
		if (k == 5)
			increase_or_decrease_it(1, ptr, sto);
		else
			increase_or_decrease_it(2, ptr, sto);
		if (ptr->type.name == 1)
			mandelbrot(ptr);
		else
			julia(ptr, ptr->cursor.x, ptr->cursor.y);
	}
	return (1);
}
