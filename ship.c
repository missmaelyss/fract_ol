/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:19:49 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/27 13:28:35 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static t_img	recurence_thermes(t_csr cursor, t_env *ptr)
{
	t_img		img;
	t_cpl		c;

	c.a = cursor.x / (ptr->width / (ptr->type.x_max -
				ptr->type.x_min)) + ptr->type.x_min;
	c.b = cursor.y / (ptr->height / (ptr->type.y_max -
				ptr->type.y_min)) + ptr->type.y_min;
	img.z.a = 0;
	img.z.b = 0;
	img.i = 0;
	while (ft_module(img.z) < 4 && img.i < ptr->type.nb_i)
	{
		if (ptr->type.puissance == 2)
			img.z = ft_recurence_ship(img.z, c);
		img.i += 1;
	}
	return (img);
}

static void		color_img(t_color color, int nb, t_env *ptr, t_csr cursor)
{
	ft_color(&color, nb, ptr);
	mlx_pixel_put_to_image(ptr->img, cursor, color);
}

void			ship(t_env *ptr)
{
	t_csr		cursor;
	t_color		color;
	t_img		img;

	cursor.y = 0;
	ptr->img = mlx_new_image(ptr->mlx, ptr->width, ptr->height);
	while (cursor.y < ptr->height)
	{
		cursor.x = 0;
		while (cursor.x < ptr->width)
		{
			img = recurence_thermes(cursor, ptr);
			if (img.i != ptr->type.nb_i && ptr->type.cc == 1)
				color_img(color, img.i * 5, ptr, cursor);
			if (img.i == ptr->type.nb_i && ptr->type.cc == 0)
				color_img(color, 4 / ft_module(img.z), ptr, cursor);
			cursor.x += 1;
		}
		cursor.y += 1;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}
