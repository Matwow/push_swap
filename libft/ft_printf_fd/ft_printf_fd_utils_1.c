/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:04:53 by maroard           #+#    #+#             */
/*   Updated: 2026/01/02 18:19:32 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	print_str(char *str, int fd)
{
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return ((int)ft_strlen(str));
}

int	print_int(int n, int fd)
{
	long long	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		len = 1;
	}
	if (nb >= 10)
	{
		len += print_int((int)(nb / 10), fd);
		nb = nb % 10;
	}
	ft_putchar_fd(nb + '0', fd);
	return (len + 1);
}

int	print_unsigned_int(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len = print_unsigned_int(n / 10, fd);
		n = n % 10;
	}
	ft_putchar_fd(n + '0', fd);
	return (len + 1);
}

int	print_hex(unsigned long n, int uppercase, int fd)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len = print_hex(n / 16, uppercase, fd);
		n = n % 16;
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else if (n >= 10 && n <= 15 && uppercase >= 1)
		ft_putchar_fd(n + 'A' - 10, fd);
	else if (n >= 10 && n <= 15 && uppercase <= 0)
		ft_putchar_fd(n + 'a' - 10, fd);
	return (len + 1);
}

int	print_ptr(void *ptr, int fd)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	return (print_hex((unsigned long)ptr, 0, fd) + 2);
}
