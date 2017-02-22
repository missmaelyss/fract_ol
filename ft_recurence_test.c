/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurence_mandelbrot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:04:00 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/21 17:02:05 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_cpl	ft_recurence_test(t_cpl z, t_cpl c)
{
	t_cpl new_z;

	new_z.a = z.a * (c.b - z.b);
	new_z.b = z.b / (c.a + 1);
	return (new_z);
}
