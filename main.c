/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:38:38 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/14 14:35:13 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>
double 	ft_module(t_cpl z)
{
	double	r;

	r = z.a * z.a + z.b * z.b;
	return (r);
}

t_cpl	ft_suite(t_cpl z, t_cpl c)
{
	t_cpl new_z;

	new_z.a = z.a*z.a - z.b*z.b + c.a;
	new_z.b = 2*z.a*z.b + c.b;
	return (new_z);
}

void	ft_pf(t_env *ptr)
{
	t_csr cursor;
	t_cpl z;
	t_cpl c;
	t_color color;
	int i;

	cursor.y = 0;
	ptr->img = mlx_new_image(ptr->mlx, ptr->img_height, ptr->img_width);
	while (cursor.y < ptr->img_height)
	{
		cursor.x = 0;
		while (cursor.x < ptr->img_height)
		{
			c.a = cursor.x / (ptr->img_height / (ptr->type.x_max - ptr->type.x_min)) + ptr->type.x_min;
			c.b = cursor.y / (ptr->img_width / (ptr->type.y_max - ptr->type.y_min)) + ptr->type.y_min;
			z.a = 0;
			z.b = 0;
			i = 0;
			while (ft_module(z) < 4 && i < ptr->type.nb_i)
			{
				z = ft_suite(z, c);
				i += 1;
			}
	/*		if (i == ptr->type.nb_i)
			{
				color.b = 0;
				color.g = 0;
				color.r = 0;
			}
	*/		if (i != ptr->type.nb_i)
			{
				color.b = 20 + i*10;
				color.g = 20;
				color.r = 20;
				mlx_pixel_put_to_image(ptr->img, cursor, color);
			}
			cursor.x += 1;
		}
		cursor.y += 1;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->img_x, ptr->img_y);
}

int		ft_esc(int k, t_env	*ptr)
{
	if (k == 53)
		exit(0);
	mlx_clear_window(ptr->mlx, ptr->win);
	if (k == 124)
	{
		ptr->img_x += 2;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->img_x, ptr->img_y);
	}
	if (k == 123)
	{
		ptr->img_x -= 2;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->img_x, ptr->img_y);
	}
	if (k == 126)
	{
		ptr->img_y -= 2;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->img_x, ptr->img_y);
	}
	if (k == 125)
	{
		ptr->img_y += 2;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->img_x, ptr->img_y);
	}
	if (k == 4)
	{
		ptr->type.x_min *= 0.9;
		ptr->type.x_max *= 0.9;
		ptr->type.y_min *= 0.9;
		ptr->type.y_max *= 0.9;
		ptr->type.nb_i += 1;
		mlx_destroy_image(ptr->mlx, ptr->img);
		ft_pf(ptr);
	}
	return (1);
}

int		ft_event(t_env *ptr)
{
//	mlx_key_hook(ptr->win, ft_esc, ptr);
	mlx_mouse_hook(ptr->win, ft_esc, ptr);
	return (1);
}

int 	main(int ac, char **av)
{
	t_env	ptr;
	t_csr	cursor;
	t_cpl	z;
	t_cpl	c;
	int		i;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 900, 900, "test");
	ptr.type.x_min = -2.1;
	ptr.type.x_max = 0.6;
	ptr.type.y_min = -1.2;
	ptr.type.y_max = 1.2;
	ptr.type.nb_i = 30;
	ptr.img_x = 0;
	ptr.img_y = 0;
	ptr.img_height = 1200;
	ptr.img_width = 1200;

	ft_pf(&ptr);
	ft_event(&ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
