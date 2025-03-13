/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:42:04 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:21:51 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	printf_putnbr(int nb, int size, int fd)
{
	if (nb == -2147483648)
	{
		size += printf_ft_putstr("-2147483648", fd);
		return (size);
	}
	else if (nb < 0)
	{
		size += printf_ft_putchar('-', fd);
		size = printf_putnbr(-nb, size, fd);
	}
	else
	{
		if (nb >= 10)
			size = printf_putnbr(nb / 10, size, fd);
		size += printf_ft_putchar(nb % 10 + '0', fd);
	}
	return (size);
}

int	printf_putnbrhexa(unsigned int nb, int size, char c, int fd)
{
	char	*base;

	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c == 'x')
		base = "0123456789abcdef";
	if (nb >= 16)
		size = printf_putnbrhexa(nb / 16, size, c, fd);
	size += printf_ft_putchar(base[nb % 16], fd);
	return (size);
}

int	printf_putnbru(unsigned int nb, int size, int fd)
{
	if (nb >= 10)
		size = printf_putnbru(nb / 10, size, fd);
	size += printf_ft_putchar(nb % 10 + '0', fd);
	return (size);
}

int	printf_hexaptr(uintptr_t nb, int size, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		size = printf_hexaptr(nb / 16, size, fd);
	size += printf_ft_putchar(base[nb % 16], fd);
	return (size);
}

int	printf_putptr(void *str, int size, int fd)
{
	uintptr_t	adress;

	adress = (uintptr_t)str;
	if (str == NULL)
	{
		size += printf_ft_putstr("(nil)", fd);
		return (size);
	}
	printf_ft_putstr("0x", fd);
	size += printf_hexaptr(adress, size, fd);
	return (size + 2);
}
