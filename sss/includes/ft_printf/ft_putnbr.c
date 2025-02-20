/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:30:05 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/11/22 16:58:57 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = nbr;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
	{
		count += ft_putchar(nb + 48);
	}
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}
