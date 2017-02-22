/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:41:04 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/21 11:05:44 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mlx_pixel_put_to_image(void *img, t_csr cursor, t_color color)
{
	char	*data;
	int		bpp;
	int		endian;
	int		sizeline;
	int		i;

	i = 0;
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	while (i != bpp / 8)
	{
		data[(cursor.y * sizeline) + (cursor.x * (bpp / 8)) + i++] = color.b;
		data[(cursor.y * sizeline) + (cursor.x * (bpp / 8)) + i++] = color.g;
		data[(cursor.y * sizeline) + (cursor.x * (bpp / 8)) + i++] = color.r;
		data[(cursor.y * sizeline) + (cursor.x * (bpp / 8)) + i++] = 0;
	}
	return (0);
}
