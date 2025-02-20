/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:16:37 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/17 02:53:29 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nbr);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_puthexa(unsigned long nbr, int check);
int	ft_printf(const char *frmt, ...);

#endif