/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:27:24 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:21:57 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	print_flags(const char *str, t_print *data, va_list params)
{
	if (str[data->i] == 'c')
		data->size += printf_ft_putchar((char)va_arg(params, int), data->fd);
	if (str[data->i] == 's')
		data->size += printf_ft_putstr(va_arg(params, char *), data->fd);
	if (str[data->i] == 'p')
		data->size += printf_putptr(va_arg(params, void *), 0, data->fd);
	if (str[data->i] == 'd' || str[data->i] == 'i')
		data->size += printf_putnbr(va_arg(params, int), 0, data->fd);
	if (str[data->i] == 'u')
		data->size += printf_putnbru(va_arg(params, unsigned int), 0, data->fd);
	if (str[data->i] == 'x' || str[data->i] == 'X')
		data->size += printf_putnbrhexa(va_arg(params, unsigned int), 0,
				str[data->i], data->fd);
	if (str[data->i] == '%')
		data->size += printf_ft_putchar('%', data->fd);
	return (data->size);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	params;
	t_print	data;

	va_start(params, str);
	data.i = 0;
	data.fd = fd;
	data.size = 0;
	if (!str || (str[data.i] == '%' && str[data.i + 1] == '\0'))
		return (-1);
	while (str[data.i])
	{
		if (str[data.i] != '%')
			data.size += printf_ft_putchar(str[data.i], data.fd);
		if (str[data.i] == '%')
		{
			data.i++;
			data.size = print_flags(str, &data, params);
			if (is_flag(str[data.i]))
				data.i++;
		}
		else
			data.i++;
	}
	va_end(params);
	return (data.size);
}
