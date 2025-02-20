/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:03:34 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/11/22 16:58:51 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long nbr, int check)
{
	int		count;
	char	*hex_lower;
	char	*hex_upper;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	count = 0;
	if (nbr < 16)
	{
		if (check == 1)
			count += ft_putchar(hex_lower[nbr]);
		if (check == 0)
			count += ft_putchar(hex_upper[nbr]);
	}
	else
	{
		count += ft_puthexa(nbr / 16, check);
		count += ft_puthexa(nbr % 16, check);
	}
	return (count);
}
