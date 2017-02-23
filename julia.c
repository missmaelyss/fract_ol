/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:09:19 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/23 15:21:05 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	julia(t_env *ptr, int x, int y)
{
	t_csr		cursor;
	t_cpl		z;
	t_cpl		c;
	t_color		color;
	int			i;

	cursor.y = 0;
	ptr->img = mlx_new_image(ptr->mlx, ptr->width, ptr->height);
	while (cursor.y < ptr->height)
	{
		cursor.x = 0;
		while (cursor.x < ptr->width)
		{
			c.a = x / (ptr->width / 4.0);
			c.b = y / (ptr->height / 4.0);
			z.a = cursor.x / (ptr->width / (ptr->type.x_max - ptr->type.x_min)) + ptr->type.x_min;
			z.b = cursor.y / (ptr->height / (ptr->type.y_max - ptr->type.y_min)) + ptr->type.y_min;
			i = 0;
			while (ft_module(z) < 4 && i < ptr->type.nb_i)
			{
				if (ptr->type.puissance == 2)
					z = ft_recurence_mandelbrot(z, c);
				else
					z = ft_recurence_mandelbrot_cube(z, c);
				i += 1;
			}
			if (i != ptr->type.nb_i)
			{
				color.b = 20 + i * 10;
				color.g = 20 + i * i;
				color.r = 20 + i * 2;
				mlx_pixel_put_to_image(ptr->img, cursor, color);
			}
			cursor.x += 1;
		}
		cursor.y += 1;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}
