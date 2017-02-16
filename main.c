/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:38:38 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/16 16:44:15 by marnaud          ###   ########.fr       */
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

void	ft_pf(t_env *ptr, int x, int y)
{
	t_csr cursor;
	t_cpl z;
	t_cpl c;
	t_color color;
	int i;

	cursor.y = 0;
	ptr->img = mlx_new_image(ptr->mlx, 900, 900);
	while (cursor.y < 900)
	{
		cursor.x = 0;
		while (cursor.x < 900)
		{
			c.a = cursor.x / (900 / (ptr->type.x_max - ptr->type.x_min)) + ptr->type.x_min;
			c.b = cursor.y / (900 / (ptr->type.y_max - ptr->type.y_min)) + ptr->type.y_min;
			z.a = 0;
			z.b = 0;
			i = 0;
			while (ft_module(z) < 4 && i < ptr->type.nb_i)
			{
				z = ft_suite(z, c);
				i += 1;
			}
			if (i != ptr->type.nb_i)
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
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}

int		ft_esc(int k, t_env	*ptr)
{
	if (k == 53)
		exit(0);
	return (1);
}

int		ft_zoom(int k, int x, int y, t_env *ptr)
{
	double sto;

	mlx_clear_window(ptr->mlx, ptr->win);
	if (k == 4)
	{
		printf("Avant\nx = %d, y = %d\nintervalle_x = %f, intervalle_y = %f\n\n", x, y, ptr->type.x_max - ptr->type.x_min, ptr->type.y_max - ptr->type.y_min);
		ptr->type.zoom += 3;
		ptr->type.x_min = ptr->type.zoom * (-2.1) / 100;
		ptr->type.x_max = ptr->type.zoom * (0.6) / 100;
		ptr->type.y_min = ptr->type.zoom * (-1.2) / 100;
		ptr->type.y_max = ptr->type.zoom * (1.2) / 100;
	
		printf("Apres\nx = %d, y = %d\nintervalle_x = %f, intervalle_y = %f\n\n", x, y, ptr->type.x_max - ptr->type.x_min, ptr->type.y_max - ptr->type.y_min);
	/*	ptr->type.x_min += ((x - 450) * 100 / 900) * (ptr->type.x_max - ptr->type.x_min) / 100;
		ptr->type.x_max += ((x - 450) * 100 / 900) * (ptr->type.x_max - ptr->type.x_min) / 100;
		ptr->type.y_min += ((y - 450) * 100 / 900) * (ptr->type.x_max - ptr->type.x_min) / 100;
		ptr->type.y_max += ((y - 450) * 100 / 900) * (ptr->type.x_max - ptr->type.x_min) / 100;
	*/	if (ptr->type.nb_i > 20)
			ptr->type.nb_i--;
		ft_pf(ptr, x, y);
	}
	if (k == 1)
	{
		printf("x_min = %f, x_max = %f, x = %d, y = %d\nnew x_max = %f\n",ptr->type.x_min, ptr->type.x_max, x, y, ptr->type.x_max * (x + 450) / 900);
		sto = ptr->type.x_max;
		ptr->type.x_max = ptr->type.x_max * (x - 450) / 900;
		ptr->type.x_min -= sto - ptr->type.x_max;
/*		printf("Avant\nx = %d, y = %d\nintervalle_x = %f, intervalle_y = %f\n\n", x, y, ptr->type.x_max - ptr->type.x_min, ptr->type.y_max - ptr->type.y_min);
		ptr->type.zoom -= 3;
		ptr->type.x_min = ptr->type.zoom * (-2.1) / 100;
		ptr->type.x_max = ptr->type.zoom * (0.6) / 100;
		ptr->type.y_min = ptr->type.zoom * (-1.2) / 100;
		ptr->type.y_max = ptr->type.zoom * (1.2) / 100;
		printf("Apres\nx = %d, y = %d\nintervalle_x = %f, intervalle_y = %f\n\n", x, y, ptr->type.x_max - ptr->type.x_min, ptr->type.y_max - ptr->type.y_min);
		
*/		//	printf("%f\n", ((x - 450) * 100 / 900) * (ptr->type.x_max - ptr->type.x_min) / 100);
/*	//	ptr->type.x_min += ((x - 450) * 100 / 900) * (ptr->type.x_max - ptr->type.x_min) / 100;
		ptr->type.x_min += (450 - x) / (900 / (ptr->type.x_max - ptr->type.x_min));
	//	ptr->type.x_max += ((x - 450) * 100 / 900) * (ptr->type.x_max - ptr->type.x_min) / 100;
		ptr->type.x_max += (450 - x) / (900 / (ptr->type.x_max - ptr->type.x_min));
	//	ptr->type.y_min += ((y - 450) * 100 / 900) * (ptr->type.x_max - ptr->type.x_min) / 100;
		ptr->type.y_min += (450 - x) / (900 / (ptr->type.x_max - ptr->type.x_min));
	//	ptr->type.y_max += ((y - 450) * 100 / 900) * (ptr->type.x_max - ptr->type.x_min) / 100;
		ptr->type.y_max += (450 - x) / (900 / (ptr->type.x_max - ptr->type.x_min));
*/		ptr->type.nb_i++;
		ft_pf(ptr, x, y);
	}
	return (1);
}

int		ft_event(t_env *ptr)
{
	mlx_key_hook(ptr->win, ft_esc, ptr);
	mlx_mouse_hook(ptr->win, ft_zoom, ptr);
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
	ptr.type.nb_i = 50;
	ptr.type.zoom = 100;

	ft_pf(&ptr, 0, 0);
	ft_event(&ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
