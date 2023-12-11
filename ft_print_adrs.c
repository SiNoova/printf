/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:36:35 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/11 21:18:13 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	adrs_numlen(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static int	ft_putnbr_adrs(unsigned long n)
{
	int				i;
	int				len;
	char			*dex;
	char			*str;

	len = adrs_numlen(n);
	dex = "0123456789abcdef";
	str = malloc(len + 1);
	if (!str)
		return (-1);
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		str[i] = dex[n % 16];
		n /= 16;
		i--;
	}
	i = write (1, str, len);
	free(str);
	return (i);
}

int	ft_putadrs(va_list args)
{
	int				count;
	void			*ptr;
	unsigned long	n;
	int				i;

	count = write(1, "0x", 2);
	ptr = va_arg(args, void *);
	if (ptr)
	{
		n = (unsigned long)ptr;
		i = ft_putnbr_adrs(n);
		if (i != -1)
			count += i;
		else
			return (i);
	}
	else
		count += write (1, "0", 1);
	return (count);
}
