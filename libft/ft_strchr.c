/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:46:02 by marnaud           #+#    #+#             */
/*   Updated: 2016/11/23 10:26:59 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, char c)
{
	int n;

	n = 0;
	if (c == 0)
	{
		while (s[n] != 0)
			n++;
		return ((char *)&s[n]);
	}
	while (s[n] != 0)
	{
		if (s[n] == c)
			return ((char *)&s[n]);
		n++;
	}
	return (0);
}
