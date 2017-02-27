/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:35:00 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/27 12:41:15 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_color(t_color *color, int nb, t_env *ptr)
{
	color->r = ptr->color.r + nb;
	color->g = ptr->color.g + nb;
	color->b = ptr->color.b + nb;
}
