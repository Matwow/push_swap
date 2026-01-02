/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:36:09 by maroard           #+#    #+#             */
/*   Updated: 2026/01/02 18:19:40 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include "libft.h"

int	print_str(char *str, int fd);
int	print_int(int n, int fd);
int	print_unsigned_int(unsigned int n, int fd);
int	print_hex(unsigned long n, int uppercase, int fd);
int	print_ptr(void *ptr, int fd);
int	print_double(double n, int fd);

#endif