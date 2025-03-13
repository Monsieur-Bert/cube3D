/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:07:41 by bert              #+#    #+#             */
/*   Updated: 2024/12/02 08:07:27 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

/**
 * Using ft_printf function to print a map of int.
 * 
 * @param tab: Pointer to pointers to an array of integer to print.
 * @param size_x: Size of each arrays, representing x axis.
 * @param size_y: Number of arrrays, representing y axis.
 * @param color: ANSI escape code used to print the tab.
 * @return None.
 */
void		ft_print_mapi(int **tab, int size_x, int size_y, char *color);

/**
 * Using ft_printf function to print an array of int.
 * 
 * @param tab: Pointer to an array of integer to print.
 * @param size: Size of the array.
 * @param color: ANSI escape code used to print the tab.
 * @return None.
 */
void		ft_print_tabi(int *tab, int size, char *color);

/**
 * Using ft_printf function to print an array of int.
 * 
 * @param tab: Pointer to an array of integer to print.
 * @param color: ANSI escape code used to print the tab.
 * @return None.
 */
void		ft_print_tabstr(char **tab, char *color);

/**
 * Outputs the character ’c’ to the given file descriptor. 
 * Using write() function.
 *
 * @param c: The character to output.
 * @param fd: The file descriptor on which to write.
 * @return None.
 */
void		ft_putchar_fd(char c, int fd);

/**
 * Outputs the string ’s’ to the given file descriptor followed by a newline.
 * Using write() function.
 *
 * @param s: The string to output.
 * @param fd: The file descriptor on which to write.
 * @return None.
 */
void		ft_putendl_fd(char *s, int fd);

/**
 * Outputs the integer ’n’ to the given file descriptor. Using write() function.
 * 
 * @param n: The integer to output.
 * @param fd: The file descriptor on which to write.
 * @return None.
 */
void		ft_putnbr_fd(int n, int fd);

/**
 * Outputs the string ’s’ to the given file descriptor 
 * followed by a newline.
 * Using write() function.
 *
 * @param s: The string to output.
 * @param fd: The file descriptor on which to write.
 * @return None.
 */
void		ft_putstr_fd(char *s, int fd);

#endif