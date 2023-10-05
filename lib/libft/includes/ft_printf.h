/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:49:07 by arigonza          #+#    #+#             */
/*   Updated: 2023/06/26 14:23:44 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *string, ...);
void	ft_putchar(int c, int *count);
void	ft_putstrc(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putunsignednbr(unsigned int nbr, int *count);
void	ft_printhexa(unsigned long long nbr, char h, int *count);
void	ft_printptr(void *ptr, int *count);

#endif
