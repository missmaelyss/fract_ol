/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:42:31 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/13 14:22:01 by marnaud          ###   ########.fr       */
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

typedef struct	s_csr
{
	int		x;
	int		y;
}				t_csr;

typedef struct	s_md
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		nb_i;
	int		zoom;
}				t_md;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_md	*type;
}				t_env;


