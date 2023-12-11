/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:53:40 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/11 17:58:02 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(va_list args);
int		ft_putchar(va_list args);
int		ft_putnbr(va_list args);
int		ft_putnbr_u(va_list args);
int		ft_putnbr_hexa(va_list args, char c);
int		ft_putadrs(va_list args);
void	f_str(char *str, long nbr, int len);

#endif