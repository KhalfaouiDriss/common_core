/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:03:55 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/11/22 16:59:57 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (*s)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}
