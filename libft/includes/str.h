/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:12:26 by bert              #+#    #+#             */
/*   Updated: 2025/03/13 14:27:35 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

/**
 * Checks if the char c is found in the string "set".
 * 
 * @param c: char to check.
 * @param set: Pointer to the string to look into.
 * @return Nonzero if the character c falls into set, 
 * and zero if not.
 */
int			ft_charinset(char c, const char *set);

/**
 * Checks for an alphanumeric character; quivalent to (isalpha(c) || isdigit(c)).
 * 
 * @param c: char to check, which must have the value of an unsigned char.
 * @return Nonzero if the character c falls into the tested class, 
 * and zero if not.
 */
int			ft_isalnum(int c);

/**
 * Checks for an alphabetic character.
In the standard "C" locale, it is equivalent to (isupper(c) || islower(c)).
 * 
 * @param c: char to check, which must have the value of an unsigned char.
 * @return Nonzero if the character c falls into the tested class, 
 * and zero if not.
 */
int			ft_isalpha(int c);

/**
 * Checks whether c is a 7-bit unsigned char value that fits into 
 * the ASCII character set
(between 0 and 127).
 * 
 * @param c: char to check, which must have the value of an unsigned char.
 * @return Nonzero if the character c falls into the tested class, 
 * and zero if not.
 */
int			ft_isascii(int c);

/**
 * Checks for a digit (0 through 9).
 * 
 * @param c: char to check, which must have the value of an unsigned char.
 * @return Nonzero if the character c falls into the tested class, 
 * and zero if not.
 */
int			ft_isdigit(int c);

/**
 * Checks for any printable character, including space (between 32 and 126).
 * 
 * @param c: char to check, which must have the value of an unsigned char.
 * @return Nonzero if the character c falls into the tested class, 
 * and zero if not.
 */
int			ft_isprint(int c);

/**
 * Checks for white-spaces letters:  space, form-feed ('\f'),
 * newline ('\n'), carriage return ('\r'), horizontal tab ('\t'),
 * and vertical tab ('\v').
 * 
 * @param c: char to check, which must have the value of an unsigned char.
 * @return Nonzero if the character c falls into the tested class, 
 * and zero if not.
 */
bool		ft_isspaces(int c);

/**
 * Allocates with malloc(3) and returns an array of strings obtained 
 * by splitting ’s’ using the
 * character ’c’ as a delimiter. The array end with a NULL pointer.
 
 * @param s: The string to be split
 * @param c: The delimiter character.
 * @return The allocated array of new strings, each one allocated 
 * (NULL if the allocation fails).
 */
char		**ft_split(char const *s, char c);

/**
 * Search and returns a pointer to the first occurrence of the character c 
 * in the string s.
 * 
 * @param s: Pointer to the string to check.
 * @param c: Character to search, means "byte".
 * @return A pointer (void *) to the matched character, or NULL if the 
 * character is not found.
 * The terminating null byte is considered part of the string, so that 
 * if c is specified as '\0', it return a pointer to the terminator.
 */
char		*ft_strchr(const char *s, int c);

/**
 * Compares two strings s1 and s2. The comparison 
 * is done using unsigned characters.
 * 
 * @param s1: Pointer to the first string to compare.
 * @param s2: Pointer to the second string to compare.
 * @return An integer: 0 if the s1 and s2 are equal; a negative value 
 * if s1 is less than s2;
 * a positive value if s1 is greater than s2.
 */
int			ft_strcmp(char *s1, char *s2);

/**
 * Duplicate a string using malloc(3), memory can be freed with free(3).
 * 
 * @param s: A pointer to the string to duplicate.
 * @return A pointer to the allocated string, or NULL if insufficient 
 * memory was available.
 */
char		*ft_strdup(const char *s);

/**
 * Applies the function ’f’ on each character of the string.
 * Each character is passed by saddress to ’f’ to be modified if 
 * necessary.
 *
 * @param s: The string on which to iterate.
 * @param f: The function to apply to each character
 * @return None.
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * Allocates with malloc(3) and returns a new string, result of the 
 * concat of ’s1’ and ’s2’.
 * 
 * @param s1: The prefix string.
 * @param s2: The suffix string.
 * @return The new allocated string (or NULL if the allocation fails).
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * Allocates with malloc(3) and returns a new string, result of the 
 * concat of the differents str.
 * 
 * @param nb_str: The nb of strings to concat.
 * @param ... Variable number of arguments (using stdarg.h).
 * @return The new allocated string (or NULL if the allocation fails).
 */
char		*ft_strjoinvar(int nb_str, ...);

/**
 * Concatenate the input string after the destination string, (as long as 
 * there is at least one byte free in dst).
 * The programmer is responsible for allocating a buffer large enough. 
 * 
 * @param dest: pointer to the new string, and NUL-terminating the result.
 * @param src: pointer to the NUL-terminated string to copy.
 * @param size: full size of the buffer (not just the length), included the 
 * terminating null byte ('\0') (unsigned long).
 * @return Length of the total string it tried to create.
 * If size = 0 it returns the length of src.
 * If src is empty, it returns the length of dest.
 * If the length of dest is larger than the size, it returns the lenght of 
 * src adding the size (unsignpip3 install --user c_formatter_42
 * ed long).
 */
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/**
 * Copy the input string into a destination string, (as long as size is
 *  larger than 0).
 * The programmer is responsible for allocating a buffer large enough. 
 * 
 * @param dest: pointer to the new string, and NUL-terminating the result.
 * @param src: pointer to the NUL-terminated string to copy.
 * @param size: full size of the buffer (not just the length), included 
 * the terminating null byte ('\0') (unsigned long).
 * @return Length of the total string it tried to create, or the length
 *  of src if size = 0 (unsigned long).
 */
size_t		ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * Calculate the length of the string pointed by s, excluding the 
 * terminating null byte ('\0').
 *
 * @param s: the string to check, which must contain a terminating null byte.
 * @return Number of bytes in the string pointed by s.
 */
size_t		ft_strlen(const char *s);

/**
 * Applies the function f to each character of the string s, 
 * using malloc(3) to collect the results.
 *
 * @param s: The string on which to iterate.
 * @param f: The function to apply to each character
 * @return The allocated string created from the successive applications 
 * of ’f' (NULL if the allocation fails).
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * Compares the n first bytes between two strings s1 and s2. The comparison 
 * is done using unsigned characters.
 * 
 * @param s1: Pointer to the first string to compare.
 * @param s2: Pointer to the second string to compare.
 * @param n: First n bytes to compare between the two strings (unsigned long).
 * @return An integer: 0 if the s1 and s2 are equal; a negative value 
 * if s1 is less than s2;
 *  a positive value if s1 is greater than s2.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * Locates the first occurrence of the null-terminated string little 
 * in the string big,
 * where not more than len characters are searched. Characters that 
 * appear after `\0' character are not searched.
 * 
 * @param big: Pointer to the string to look into.
 * @param little: Pointer to the string to find.
 * @param len: The maximum character to search into the string big 
 * (unsigned long).
 * @return If little is an empty string, big is returned; if little 
 * occurs nowhere big, NULL is returned;
 * otherwise a pointer to the first character of the first occurrence 
 * of little is returned.
 */
char		*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * Search and returns a pointer to the last occurrence of the character 
 * c in the string s.
 * 
 * @param s: Pointer to the string to check.
 * @param c: Character to search, means "byte".
 * @return A pointer (void *) to the matched character, or NULL if the 
 * character is not found.
 * The terminating null byte is considered part of the string, so that 
 * if c is specified as '\0', it return a pointer to the terminator.
 */
char		*ft_strrchr(const char *s, int c);

/**
 * Allocates with malloc(3) and returns a copy of 
 * ’s1’ with the characters specified in ’set’ removed
 * from the beginning and the end of the string.
 *
 * @param s1: The string to be trimmed.
 * @param s2: The reference set of characters to trim.
 * @return The trimmed allocated string (NULL if the allocation fails).
 */
char		*ft_strtrim(char const *s1, char const *set);

/**
 * Allocates with malloc(3) and returns a substring from the string ’s’.
 * 
 * @param s: The string from which to create the substring.
 * @param start: The start index of the substring in the string ’s’.
 * @param len: The maximum length of the substring.
 * @return The allocated substring (or NULL if the allocation fails).
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Convert uppercase letters to lowercase.
 * 
 * @param c: char to check, which must have the value of an unsigned char.
 * @return If c is a uppercase letter, returns its lowercase equivalent,
 * if an lowercase representation exists in the current locale. Otherwise, 
 * it returns c.
 */
int			ft_tolower(int c);

/**
 * Convert lowercase letters to uppercase.
 * 
 * @param c: char to check, which must have the value of an unsigned char.
 * @return If c is a lowercase letter, returns its uppercase equivalent,
 * if an uppercase representation exists in the current locale. Otherwise, 
 * it returns c.
 */
int			ft_toupper(int c);

/**
 * Allocates with malloc(3) and returns an array of strings obtained 
 * by splitting ’s’ using the
 * character ’c’ as a delimiter. The array end with a NULL pointer.
 
 * @param s: The string to be split
 * @param set: Set with delimiters characters, using ft_charinset
 * @return The allocated array of new strings, each one allocated 
 * (NULL if the allocation fails).
 */
char		**ft_setsplit(char const *s, char *set);

/**
 * Count the number of words into the string s, separated by the char c.
 * 
 * @param s: The string to look into
 * @param c: The delimiter beteen each words
 * @return The number of words in the string s
 */
int			ft_count_words(char const *s, char c);

/**
 * Count the number of words into the string s, separated by the char c.
 * 
 * @param s: The string to look into
 * @param s: The string with differents delimiters possibilities
 * @return The number of words in the string s
 */
int			ft_count_wordset(char const *s, char *set);

#endif
