/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:42:04 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:21:54 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	printf_ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

int	printf_ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}

int	printf_ft_putstr(char *str, int fd)
{
	if (!str)
		str = "(null)";
	write(fd, str, printf_ft_strlen(str));
	return (printf_ft_strlen(str));
}
