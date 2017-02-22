/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:42:31 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/22 16:26:43 by marnaud          ###   ########.fr       */
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
	int		name;	
	int		pause;
	double	PuissanceZoom;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		nb_i;
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
	int		height;
	int		width;
	t_csr	cursor;
	t_type	type;
}				t_env;

void			mandelbrot(t_env *ptr);
void			test(t_env *ptr);
void			julia(t_env *ptr, int x, int y);
double			ft_module(t_cpl z);
t_cpl			ft_recurence_mandelbrot(t_cpl z, t_cpl c);
t_cpl			ft_recurence_test(t_cpl z, t_cpl c);
int				ft_zoom(int k, int x, int y, t_env *ptr);
int				ft_follow_mouse(int x, int y, t_env *ptr);
int				mlx_pixel_put_to_image(void	*img, t_csr cursor, t_color color);
