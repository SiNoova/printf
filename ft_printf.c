/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:52:07 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/11 21:53:13 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checker(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(args));
	else if (c == 's')
		return (ft_putstr(args));
	else if (c == 'p')
		return (ft_putadrs(args));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(args));
	else if (c == 'u')
		return (ft_putnbr_u(args));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_hexa(args, c));
	else if (c != '\0')
		return (write(1, &c, 1));
	else 
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		j;

	i = -1;
	count = 0;
	va_start(args, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[++i])
	{
		if (str[i] != '%')
			count += write(1, &str[i], 1);
		else
		{
			j = checker(str[++i], args);
			if (j != -1)
				count += j;
			else
				return (j);
		}
	}
	va_end (args);
	return (count);
}
