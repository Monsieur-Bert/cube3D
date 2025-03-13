/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:14:52 by bert              #+#    #+#             */
/*   Updated: 2025/01/25 16:16:54 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

/**
 * Return the absolute value from an integer
 * 
 * @param nb: the integer.
 * @return The absolute value of the integer nb.
 */
int			ft_abs(int nb);

/**
 * Converts the initial portion of the string pointed to by nptr to int,
 * stopping at the first character which is not a valid digit 
 * (between 0 and 9).
 * 
 * @param nptr: Pointer to the string to convert, may begin 
 * with an arbitrary amount of white space
 * (as determined by isspace(3)) followed by a single optional '+' or '-' sign.
 * @return The converted value or 0 on error.
 */
int			ft_atoi(const char *nptr);

/**
 * Converts the initial portion of the string pointed to by nptr to long,
 * stopping at the first character which is not a valid digit 
 * (between 0 and 9).
 * 
 * @param nptr: Pointer to the string to convert, may begin 
 * with an arbitrary amount of white space
 * (as determined by isspace(3)) followed by a single optional '+' or '-' sign.
 * @return The converted value or 0 on error.
 */
long int	ft_atol(const char *nptr);

/**
 * Allocates with malloc(3) and returns a string representing the 
 * integer received as an argument.
 * Negative numbers are handled.
 *
 * @param n: the integer to convert.
 * @return The allocated string representing the integer 
 * (NULL if the allocation fails).
 */
char		*ft_itoa(int n);

/**
 * Return the larger value of x and y.
 *
 * @param x: first integer to compare.
 * @param y: second integer to compare.
 * @return Max interger between x and y 
 */
int	ft_max(int x, int y);

/**
 * Return the lesser value of x and y.
 *
 * @param x: first integer to compare.
 * @param y: second integer to compare.
 * @return Min interger between x and y 
 */
int	ft_min(int x, int y);

/**
 * Returns the value of x raised to the power of y.
 *
 * @param nb: nb integer to raise.
 * @param pow: power to raise to.
 * @return On success, return the value of x to the power of y.
 */
int	ft_pow(int nb, int power);

/**
 * Return the nonnegative square root of x.
 * 
 * @param nb: nb integer to raise.
 * @return On success, these functions return return the square root of x.
 */
int	ft_sqrt(int nb);

#endif