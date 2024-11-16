/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:40:36 by dkhalfao          #+#    #+#             */
/*   Updated: 2024/10/31 18:40:40 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	dl;

	i = ft_strlen(dst);
	dl = ft_strlen(dst);
	y = 0;
	if (n && ft_strlen(dst) <= n)
	{
		while (src[y] != '\0' && i < (n - 1))
		{
			dst[i] = src[y];
			i++;
			y++;
		}
		dst[i] = '\0';
	}
	if (n == 0)
		dl = 0;
	if (n < dl)
		dl = n;
	return (dl + ft_strlen((char *)src));
}
