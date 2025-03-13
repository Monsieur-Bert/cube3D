/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:40:08 by antauber          #+#    #+#             */
/*   Updated: 2024/12/09 17:12:54 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4200
# endif

/**
 * Read and return each line of the fd passing in parameter.
 * The function keeps the non-return file into a static variable.
 * A BUFFER-SIZE could be defined at the compilation (42 by default).
 * 
 * @param fd: File descriptor to read from.
 * @return Return the readed line for each call (NULL if there is
 * nothing else to read or if an error has occured).
 */
char	*get_next_line(int fd);

/*	get_next_line_utils	*/
size_t	gnl_strlen(const char *s);
char	*gnl_ft_strdup(const char *s);
void	*gnl_to_free(char *store, char *buffer);

#endif
