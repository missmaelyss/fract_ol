/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:38:38 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/23 16:09:20 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	wich_function(t_env *ptr)
{		
	if (ptr->type.name == 1)
		mandelbrot(ptr);
	if (ptr->type.name == 2)
		julia(ptr, ptr->cursor.x, ptr->cursor.y);
	if (ptr->type.name == 3)
		ship(ptr);
}

int		ft_esc(int k, t_env *ptr)
{	
	if (k == 8)
	{
		ptr->type.cc = (ptr->type.cc + 1) % 2;
		wich_function(ptr);
	}
	if (k == 35)
		ptr->type.pause = (ptr->type.pause + 1) % 2;
	if (k == 78)
	{
		ptr->type.nb_i--;
		wich_function(ptr);
	}
	if (k == 69)
	{
		ptr->type.nb_i++;
		wich_function(ptr);
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
	//mlx_loop(ptr->mlx);
	return (1);
}
