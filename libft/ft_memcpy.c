/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:28:26 by dkhalfao          #+#    #+#             */
/*   Updated: 2024/11/13 18:43:08 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dest;
	i = 0;
	if (len == 0 || dest == src)
		return (dest);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
