/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:35:28 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/11 16:13:57 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	f_str(char *str, long nbr, int len)
{
	int	dex;

	dex = len - 1;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		str[dex--] = (nbr % 10) + '0';
		nbr /= 10;
	}
}

static char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;

	nbr = n;
	len = numlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	f_str(str, nbr, len);
	return (str);
}

int	ft_putnbr(va_list args)
{
	int		i;
	char	*str;
	int		x;

	i = va_arg(args, int);
	str = ft_itoa(i);
	x = write(1, str, numlen(i));
	free(str);
	return (x);
}
