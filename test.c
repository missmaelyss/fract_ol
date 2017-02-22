/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:57:55 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/21 16:59:11 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	test(t_env *ptr)
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
			c.a = cursor.x / (ptr->width / (ptr->type.x_max - ptr->type.x_min)) + ptr->type.x_min;
			c.b = cursor.y / (ptr->height / (ptr->type.y_max - ptr->type.y_min)) + ptr->type.y_min;
			z.a = 0;
			z.b = 0;
			i = 0;
			while (ft_module(z) < 7 && i < ptr->type.nb_i)
			{
				z = ft_recurence_test(z, c);
				i += 1;
			}
			if (i != ptr->type.nb_i)
			{
				color.b = 20 + i * 10;
				color.g = 20 + i * 10;
				color.r = 20 + i * 10;
				mlx_pixel_put_to_image(ptr->img, cursor, color);
			}
			cursor.x += 1;
		}
		cursor.y += 1;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}
