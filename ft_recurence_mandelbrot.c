/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurence_mandelbrot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:04:00 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/21 12:16:45 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_cpl	ft_recurence_mandelbrot(t_cpl z, t_cpl c)
{
	t_cpl new_z;

	new_z.a = z.a * z.a - z.b * z.b + c.a;
	new_z.b = 2 * z.a * z.b + c.b;
	return (new_z);
}
