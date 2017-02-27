/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurence_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:08:48 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/27 13:23:54 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_cpl	ft_recurence_ship(t_cpl z, t_cpl c)
{
	t_cpl new_z;

	new_z.a = z.a * z.a - z.b * z.b + c.a;
	new_z.b = 2 * (sqrt(z.a * z.a) * sqrt(z.b * z.b)) + c.b;
	return (new_z);
}
