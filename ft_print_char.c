/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:24:28 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/11 16:17:07 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	ft_putstr(va_list args)
{
	char	*str;
	int		i;

	str = va_arg (args, char *);
	if (str)
	{
		i = write(1, str, strlen(str));
		return (i);
	}
	else
	{
		i = write(1, "(null)", 6);
		return (i);
	}
}
