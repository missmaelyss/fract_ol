/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_follow_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:18:19 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/23 12:26:41 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int			ft_follow_mouse(int x, int y, t_env *ptr)
{
	if (ptr->type.pause == 0)
	{
		ptr->cursor.x = x;
		ptr->cursor.y = y;
		julia(ptr, ptr->cursor.x, ptr->cursor.y);
	}
	return (1);
}
