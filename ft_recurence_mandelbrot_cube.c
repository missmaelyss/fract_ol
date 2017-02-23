/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurence_mandelbrot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:04:00 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/23 13:27:47 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_cpl	ft_recurence_mandelbrot_cube(t_cpl z, t_cpl c)
{
	t_cpl new_z;

	new_z.a = z.a * z.a * z.a - ( 3 * z.b * z.b * z.a) + c.a;
	new_z.b = 3 * z.a * z.a * z.b - z.b * z.b * z.b + c.b;
	return (new_z);
}
