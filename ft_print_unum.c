/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:38:13 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/11 17:25:00 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(unsigned int n)
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

int	ft_putnbr_u(va_list args)
{
	int		i;
	char	*str;
	int		x;

	i = va_arg(args, unsigned int);
	str = ft_itoa(i);
	x = write(1, str, numlen(i));
	free(str);
	return (x);
}
