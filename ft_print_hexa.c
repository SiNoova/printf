/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:30:56 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/11 21:24:09 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

static int	hexa_numlen(unsigned int n)
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

int	ft_putnbr_hexa(va_list args, char c)
{
	int				i;
	unsigned int	n;
	char			*dex;
	char			*str;

	n = va_arg(args, unsigned int);
	i = hexa_numlen(n);
	if (c == 'x')
		dex = "0123456789abcdef";
	else
		dex = "0123456789ABCDEF";
	str = malloc(i + 1);
	if (!str)
		return (-1);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = dex[n % 16];
		n /= 16;
		i--;
	}
	i = write (1, str, strlen(str));
	free(str);
	return (i);
}
