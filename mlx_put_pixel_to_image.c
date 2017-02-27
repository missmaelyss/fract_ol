/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:41:04 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/27 13:35:32 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

/*
**	ed = edian
**	sl = sizeline
**	c = cursor
*/

int	mlx_pixel_put_to_image(void *img, t_csr c, t_color color)
{
	char	*data;
	int		bpp;
	int		ed;
	int		sl;
	int		i;

	i = 0;
	data = mlx_get_data_addr(img, &bpp, &sl, &ed);
	while (i != bpp / 8)
	{
		if (ed > 0)
		{
			data[(c.y * sl) + (c.x * (bpp / 8)) + i++] = color.b;
			data[(c.y * sl) + (c.x * (bpp / 8)) + i++] = color.g;
			data[(c.y * sl) + (c.x * (bpp / 8)) + i++] = color.r;
		}
		else
		{
			data[(c.y * sl) + (c.x * (bpp / 8)) + i++] = color.r;
			data[(c.y * sl) + (c.x * (bpp / 8)) + i++] = color.g;
			data[(c.y * sl) + (c.x * (bpp / 8)) + i++] = color.b;
		}
		data[(c.y * sl) + (c.x * (bpp / 8)) + i++] = 0;
	}
	return (0);
}
