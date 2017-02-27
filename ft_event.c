/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:38:38 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/27 13:56:58 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	wich_function(t_env *ptr)
{
	ft_clear(ptr);
	if (ptr->type.name == 1)
		mandelbrot(ptr);
	if (ptr->type.name == 2)
		julia(ptr, ptr->cursor.x, ptr->cursor.y);
	if (ptr->type.name == 3)
		ship(ptr);
}

void	change_color(t_env *ptr)
{
	ptr->color.r = (ptr->color.r / 4) * 2 + 12;
	ptr->color.g = (ptr->color.g * 4) / 3 - 42;
	ptr->color.b = ptr->color.b + 42;
	if (ptr->color.r > 254)
		ptr->color.r -= 200;
	if (ptr->color.g > 254)
		ptr->color.g -= 200;
	if (ptr->color.b > 254)
		ptr->color.b -= 200;
}

int		ft_esc(int k, t_env *ptr)
{
	if (k == 8 || k == 49)
	{
		if (k == 8)
			ptr->type.cc = (ptr->type.cc + 1) % 2;
		else
			change_color(ptr);
		wich_function(ptr);
	}
	if (k == 35)
		ptr->type.pause = (ptr->type.pause + 1) % 2;
	if (k == 78 || k == 69)
	{
		if (k == 69 && ptr->type.nb_i < 200)
			ptr->type.nb_i += 2;
		ptr->type.nb_i--;
		wich_function(ptr);
	}
	if (k == 15)
	{
		ft_clear(ptr);
		draw_first_img(ptr, ptr->cas);
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
		mlx_hook(ptr->win, 6, (1L << 6), ft_follow_mouse, ptr);
	}
	return (1);
}
