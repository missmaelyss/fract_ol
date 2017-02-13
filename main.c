/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:38:38 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/13 14:35:50 by marnaud          ###   ########.fr       */
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
	int i;

	cursor.y = 0;
	while (cursor.y < 900)
	{
		cursor.x = 0;
		while (cursor.x < 900)
		{
			c.a = cursor.x / (900 / (ptr->type->x_max - ptr->type->x_min)) + ptr->type->x_min;
			c.b = cursor.y / (900 / (ptr->type->y_max - ptr->type->y_min)) + ptr->type->y_min;
			z.a = 0;
			z.b = 0;
			i = 0;
			while (ft_module(z) < 4 && i < 30)
			{
				z = ft_suite(z, c);
				i += 1;
			}
			if (i == 30)
				mlx_pixel_put(ptr->mlx, ptr->win, cursor.x, cursor.y, 0x00);
			else
				mlx_pixel_put(ptr->mlx, ptr->win, cursor.x, cursor.y, 20 + i*10);
			cursor.x += 1;
		}
		cursor.y += 1;
	}
}

int		ft_esc(int k, t_env	*ptr)
{
	printf("%d\n", k);
	if (k == 53)
		exit(0);
	if (k == 4)
	{
		ptr->type->x_min += 0.5;
		ptr->type->x_max -= 0.5;
		ptr->type->y_min += 0.5;
		ptr->type->y_min -= 0.5;
		mlx_clear_window(ptr->mlx, ptr->win);
		ft_pf(ptr);
	}
	return (1);
}

int		ft_event(t_env *ptr)
{
	mlx_key_hook(ptr->win, ft_esc, ptr);
	mlx_mouse_hook(ptr->win, ft_esc, ptr);
	return (1);
}



int 	main(int ac, char **av)
{
	t_env	ptr;
	t_csr	cursor;
	t_cpl	z;
	t_cpl	c;
	t_md	md;
	int		i;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 900, 900, "test");
	ptr.type = &md;
	md.x_min = -2.1;
	md.x_max = 0.6;
	md.y_min = -1.2;
	md.y_max = 1.2;
	ft_pf(&ptr);
	ft_event(&ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
