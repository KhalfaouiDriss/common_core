/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:39:44 by dkhalfao          #+#    #+#             */
/*   Updated: 2024/11/13 04:09:03 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(str);
	dest = malloc((sizeof(char) * size) + 1);
	if (!str)
		return (NULL);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, str, size + 1);
	return (dest);
}
