/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:38:38 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/27 13:51:20 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	exit_error(int i, char *av)
{
	if (i == 1)
		ft_putstr("WARNING : fract_ol works with one file\n");
	else
	{
		ft_putstr("WARING : ");
		ft_putstr(av);
		ft_putstr(" not a valid file\n");
	}
	ft_putstr("usage: ./fract_ol [julia][julia3]");
	ft_putstr("[mandelbrot][mandelbrot3][ship]\n");
}

int		read_arg(char *av, t_env *ptr)
{
	int	cas;

	cas = 0;
	(ft_strcmp(av, "mandelbrot") == 0) ? (cas = 1) : (cas += 0);
	(ft_strcmp(av, "mandelbrot3") == 0) ? (cas = 2) : (cas += 0);
	(ft_strcmp(av, "julia") == 0) ? (cas = 3) : (cas += 0);
	(ft_strcmp(av, "julia3") == 0) ? (cas = 4) : (cas += 0);
	(ft_strcmp(av, "ship") == 0) ? (cas = 5) : (cas += 0);
	if (cas > 0)
	{
		ptr->cas = cas;
		ptr->win = mlx_new_window(ptr->mlx, ptr->width, ptr->height, av);
		draw_first_img(ptr, cas);
		ft_event(ptr);
		return (0);
	}
	exit_error(0, av);
	exit(0);
}

int		main(int ac, char **av)
{
	t_env	ptr;

	if (ac == 2)
		ptr.mlx = mlx_init();
	else
		exit_error(1, NULL);
	ptr.width = 600;
	ptr.height = 600;
	if (ac == 2)
	{
		read_arg(av[1], &ptr);
		mlx_loop(ptr.mlx);
	}
	return (0);
}
