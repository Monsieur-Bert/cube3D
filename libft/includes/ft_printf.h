/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:26:47 by antauber          #+#    #+#             */
/*   Updated: 2024/12/02 08:28:48 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_print
{
	int	fd;
	int	size;
	int	i;
}		t_print;

/**
 * Produce an output in the specified fd, as a formated string and
 * convert the differents arguments (specified types with % flags).
 * 
 * @param str: String that specifies how subsequent arguments.
 * @param fd: The file descriptor on which to write.
 * @param ... Variable number of arguments (using stdarg.h).
 * @return Return the number of characters printed
 * (excluding the null byte used to end output to strings).
 */
int	ft_printf(int fd, const char *str, ...);

/*	ft_printf_utils		*/
int	printf_ft_strlen(const char *str);
int	printf_ft_putchar(char c, int fd);
int	printf_ft_putstr(char *str, int fd);

/*	ft_printf_utils_nbr	*/
int	printf_putnbr(int nb, int size, int fd);
int	printf_putnbrhexa(unsigned int nb, int size, char c, int fd);
int	printf_putnbru(unsigned int nb, int size, int fd);
int	printf_hexaptr(uintptr_t nb, int size, int fd);
int	printf_putptr(void *str, int size, int fd);

#endif