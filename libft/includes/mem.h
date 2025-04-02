/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:14:54 by bert              #+#    #+#             */
/*   Updated: 2025/04/02 11:03:36 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

/**
 * Erases the data in the n bytes of the memory starting at the location 
 * pointed to by s, 
 * by writing zeros (bytes containing '\0') to that area.
 * @param s: pointer to the memory area.
 * @param n: first bytes to fill (unsigned long).
 * @return None.
 */
void		ft_bzero(void *s, size_t n);

/**
 * Allocates memory for an array of nmemb elements of size bytes each 
 * and set the allocated memory to zero.
 *
 * @param nmemb: Number of member to allocate.
 * @param size: Size bytes of each member.
 * @return A pointer to the allocated memory. On error, these functions 
 * return NULL and set errno.
 * If nmemb or size is 0,returns a unique pointer value that can later be 
 * successfully passed to free().
 * @note If the multiplication of nmemb and size would result in integer 
 * overflow, then returns an error.
  */
void		*ft_calloc(size_t nmemb, size_t size);

/**
 * Using free(3) to free a allocated array of arrays and each of
 * the allocated arrays of integers.
 * 
 * @param tab: An array of pointers to allocated integers arrays.
 * @param size: The size of the array. 
 * @return None.
 */
void		*ft_free_mapi(int **map, int size);

/**
 * Using free(3) to free a allocated array of strings and each of
 * the allocated strings.
 * 
 * @param tab: An array of pointers to allocated strings.
 * @return None.
 */
void		*ft_free_tabstr(char **tab);

/**
 * Scans the initial n bytes of the memory area pointed to by s for the 
 * first instance of c.
 * Both c and the bytes of the memory area pointed to by s are interpreted 
 * as unsigned char
 * 
 * @param s: Pointer to the memory area to check.
 * @param c: Character to search, means "byte".
 * @param n: First n bytes to search (unsigned long).
 * @return A pointer (void *) to the matching byte, or NULL if the 
 * character does not occur in the given memory area.
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * Compares the first n bytes, each interpreted as (unsigned char), 
 * of the memory areas s1 and s2.
 * 
 * @param s1: Pointer to the first memory area to compare.
 * @param s2: Pointer to the second memory area to compare.
 * @param n: First n bytes to compare between the memory areas (unsigned long).
 * @return An integer less than, equal to, or greater than zero if the first n
 *  bytes of s1 is found.
 * For a nonzero return value, the sign is determined by the sign of the
 *  difference between
 * the first pair of bytes (interpreted as unsigned char) 
 * that differ in s1 and s2.
 * If n is zero, the return value is zero.
 */

int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Copies n bytes from memory area src to memory area dest.
 * 
 * @param dest: pointer to the new memory area.
 * @param src: pointer to the memory area to copy.
 * @param n: first bytes to copy (unsigned long).
 * @return A pointer to dest (void *).
 * @note Produces undefined behavior with overlapping, use ft_memmove 
 * if the memory areas do overlap.
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Copies n bytes from memory area src to memory area dest.
 * 
 * @param dest: pointer to the new memory area.
 * @param src: pointer to the memory area to copy.
 * @param n: first bytes to copy (unsigned long).
 * @return A pointer to dest (void *).
 * @note The memory areas may overlap: copying takes place
 * as though the bytes in src are first copied into a temp
 * array and are then copied from the temp to dest.
 */
void		*ft_memmove(void *dest, const void *src, size_t n);

/**
 * Fill the first n bytes of the memory area pointed to by s with the 
 * constant byte c.
 * 
 * @param s: pointer to the memory area.
 * @param c: constant byte which must have the value of an unsigned char.
 * @param n: first bytes to fill (unsigned long).
 * @return A pointer to the memory area s (void *).
 */
void		*ft_memset(void *s, int c, size_t n);

#endif
