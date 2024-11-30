int	ft_putnbr(int nbr)
{
    int i = 0;
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return 11;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
        i++;
		nbr = -nbr;
	}
	if (nbr > 9)
	{
        i++;
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	else
        i++;
		ft_putchar(nbr + '0');
    return i;
}