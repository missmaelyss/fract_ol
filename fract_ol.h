/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:42:31 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/14 14:24:39 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft/libft.h"
#include "minilibx/mlx.h"

typedef struct	s_cpl
{
	double	a;
	double	b;
}				t_cpl;

typedef struct	s_cursor
{
	int		x;
	int		y;
}				t_csr;

typedef struct	s_type
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		nb_i;
	int		zoom;
}				t_type;

typedef	struct	s_color
{
	int		b;
	int		g;
	int		r;
}				t_color;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_x;
	int		img_y;
	int		img_height;
	int		img_width;
	t_type	type;
}				t_env;

void			ft_initialization(t_env *ptr);
void			ft_create_fractale(t_env *ptr);
int				mlx_pixel_put_to_image(void	*img, t_csr cursor, t_color color);
